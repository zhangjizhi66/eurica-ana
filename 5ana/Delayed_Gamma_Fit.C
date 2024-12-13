void gate(int type, double eff)
{
    hh1->ProjectionX(Form("h%d",e),e1,e2);
    TH1D *hdt = (TH1D*)gROOT->FindObject(Form("h%d",e));
    TH1D *hbg = new TH1D("hbg","hbg",nbins,-1000,10000);
    for (unsigned int i=0;i<b.size();i++){
        hh1->ProjectionX(Form("b%d",b[i]),b[i],b[i]);
        TH1D *hbtemp = (TH1D*)gROOT->FindObject(Form("b%d",b[i]));
        hbg->Add(hbg,hbtemp,1,1);
    }
    double weight = (double)(e2-e1+1)/b.size();
    hdt->Add(hdt,hbg,1,-weight);
    
    TF1 *f1;
    if (type==3){  // two components + prompt
        f1 = new TF1("ff2",ff2,xmin,xmax,7);
        f1->SetParameter(3,100);
        f1->SetParLimits(3,0,1e8);
        f1->SetParameter(4,270);
        f1->SetParLimits(4,0,1e8);
        f1->SetParameter(5,10);
        f1->SetParLimits(5,0,1e8);
        f1->SetParameter(6,3000);
        f1->SetParLimits(6,2000,3500);
    }
    if (type==4){  // one component + prompt
        f1 = new TF1("ff1",ff1,xmin,xmax,5);
        f1->SetParameter(3,10);
        f1->SetParLimits(3,0,1e8);
        f1->SetParameter(4,3000);
        f1->SetParLimits(4,2000,3500);
    }
    f1->SetNpx(xmax-xmin);
    f1->FixParameter(0,0);
    f1->SetParameter(1,1000);
    f1->SetParLimits(1,0,1e8);
    f1->SetParameter(2,50);
    f1->SetParLimits(2,30,100);
    
    hdt->Fit(f1,"R");
    hdt->Draw();
    c1->Draw();
    
    if (type==3){
        cout<<'\n'<<"T1/2 = prompt and "<<f1->GetParameter(4)<<" and "<<f1->GetParameter(6)<<" ns"<<endl;
        
        TF1 *fgaus = new TF1("fgaus","gaus",-1000,10000);
        fgaus->SetParameter(0, f1->GetParameter(1));
        fgaus->SetParError(0, f1->GetParError(1));
        fgaus->SetParameter(1, 0);
        fgaus->SetParError(1, 0);
        fgaus->SetParameter(2, f1->GetParameter(2));
        fgaus->SetParError(2, f1->GetParError(2));
        
        TF1 *fconv1 = new TF1("fconv1",fconv,-1000,10000,3);
        fconv1->SetParameter(0, f1->GetParameter(3));
        fconv1->SetParError(0, f1->GetParError(3));
        fconv1->SetParameter(1, f1->GetParameter(4));
        fconv1->SetParError(1, f1->GetParError(4));
        fconv1->SetParameter(2, f1->GetParameter(2));
        fconv1->SetParError(2, f1->GetParError(2));
        
        TF1 *fconv2 = new TF1("fconv2",fconv,-1000,10000,3);
        fconv2->SetParameter(0, f1->GetParameter(5));
        fconv2->SetParError(0, f1->GetParError(5));
        fconv2->SetParameter(1, f1->GetParameter(6));
        fconv2->SetParError(1, f1->GetParError(6));
        fconv2->SetParameter(2, f1->GetParameter(2));
        fconv2->SetParError(2, f1->GetParError(2));
        
        TF1 *fconv22 = new TF1("fconv22",fconv,-1000,10000,3);
        fconv22->SetParameter(0, f1->GetParameter(5));
        fconv22->SetParError(0, f1->GetParError(5));
        fconv22->SetParameter(1, f1->GetParameter(4));
        fconv22->SetParError(1, f1->GetParError(4));
        fconv22->SetParameter(2, f1->GetParameter(2));
        fconv22->SetParError(2, f1->GetParError(2));
        
        ifstream ifs(Form("spectra/Delay_Fit_hist_%d",e));
        for (int i=1; i<=220; i++)
            ifs<<hdt->GetBinLowEdge(i)+hdt->GetBinWidth(i)/2.<<'\n';
        ifs<<'\n';
        for (int i=1; i<=220; i++)
            ifs<<hdt->GetBinContent(i)<<'\n';
        ifs.close();
        
        ifstream ifs0(Form("spectra/Delay_Fit_gaus_%d",e));
        for (int i=-1000; i<=10000; i+=10)
            ifs0<<i<<'\n';
        ifs0<<'\n';
        for (int i=-1000; i<=10000; i+=10)
            ifs0<<fgaus->Eval(i)<<'\n';
        ifs0.close();
        
        ifstream ifs1(Form("spectra/Delay_Fit_conv1_%d",e));
        for (int i=-1000; i<=10000; i+=10)
            ifs1<<i<<'\n';
        ifs1<<'\n';
        for (int i=-1000; i<=10000; i+=10)
            ifs1<<fconv1->Eval(i)<<'\n';
        ifs1.close();
        
        ifstream ifs2(Form("spectra/Delay_Fit_conv2_%d",e));
        for (int i=-1000; i<=10000; i+=10)
            ifs2<<i<<'\n';
        ifs2<<'\n';
        for (int i=-1000; i<=10000; i+=10)
            ifs2<<fconv2->Eval(i)-fconv22->Eval(i)<<'\n';
        ifs2.close();
        
        // /eff/50/norm1
        cout<<'\n'<<"integral = "<<fgaus->Integral(-1000,10000)<<" and "<<fconv1->Integral(-1000,10000)<<" and "<<(fconv2->Integral(-1000,10000) - fconv22->Integral(-1000,10000))<<endl;
        
        TH1D *hgaus = new TH1D("hgaus","hgaus",10000,0,1000000);
        TH1D *hconv1 = new TH1D("hconv1","hconv1",10000,0,1000000);
        TH1D *hconv2 = new TH1D("hconv2","hconv2",10000,0,1000000);
        
        double p[7];
        for (int i=0; i<1000; i++){
            for (int ipar=0; ipar<7; ipar++)
                p[ipar] = gr->Gaus(f1->GetParameter(ipar), f1->GetParError(ipar));
            
            fgaus->SetParameter(0, p[1]);
            fgaus->SetParameter(1, 0);
            fgaus->SetParameter(2, p[2]);

            fconv1->SetParameter(0, p[3]);
            fconv1->SetParameter(1, p[4]);
            fconv1->SetParameter(2, p[2]);

            fconv2->SetParameter(0, p[5]);
            fconv2->SetParameter(1, p[6]);
            fconv2->SetParameter(2, p[2]);

            fconv22->SetParameter(0, p[5]);
            fconv22->SetParameter(1, p[4]);
            fconv22->SetParameter(2, p[2]);
            
            hgaus->Fill(fgaus->Integral(-1000,10000));
            hconv1->Fill(fconv1->Integral(-1000,10000));
            hconv2->Fill((fconv2->Integral(-1000,10000) - fconv22->Integral(-1000,10000)));
        }
        
        cout<<"integral error = "<<hgaus->GetStdDev()<<" and "<<hconv1->GetStdDev()<<" and "<<hconv2->GetStdDev()<<endl;
        
        delete fgaus;
        delete fconv1;
        delete fconv2;
        delete fconv22;
        
        delete hgaus;
        delete hconv1;
        delete hconv2;
    }
    if (type==4){
        cout<<'\n'<<"T1/2 = prompt and "<<f1->GetParameter(4)<<" ns"<<endl;
        
        TF1 *fgaus = new TF1("fgaus","gaus",-1000,10000);
        fgaus->SetParameter(0, f1->GetParameter(1));
        fgaus->SetParError(0, f1->GetParError(1));
        fgaus->SetParameter(1, 0);
        fgaus->SetParError(1, 0);
        fgaus->SetParameter(2, f1->GetParameter(2));
        fgaus->SetParError(2, f1->GetParError(2));
        
        TF1 *fconv1 = new TF1("fconv1",fconv,-1000,10000,3);
        fconv1->SetParameter(0, f1->GetParameter(3));
        fconv1->SetParError(0, f1->GetParError(3));
        fconv1->SetParameter(1, f1->GetParameter(4));
        fconv1->SetParError(1, f1->GetParError(4));
        fconv1->SetParameter(2, f1->GetParameter(2));
        fconv1->SetParError(2, f1->GetParError(2));
        
        cout<<'\n'<<"integral = "<<fgaus->Integral(-1000,10000)<<" and "<<fconv1->Integral(-1000,10000)<<endl;
        
        TH1D *hgaus = new TH1D("hgaus","hgaus",10000,0,1000000);
        TH1D *hconv1 = new TH1D("hconv1","hconv1",10000,0,1000000);
        
        double p[5];
        for (int i=0; i<1000; i++){
            for (int ipar=0; ipar<5; ipar++)
                p[ipar] = gr->Gaus(f1->GetParameter(ipar), f1->GetParError(ipar));
            
            fgaus->SetParameter(0, p[1]);
            fgaus->SetParameter(1, 0);
            fgaus->SetParameter(2, p[2]);

            fconv1->SetParameter(0, p[3]);
            fconv1->SetParameter(1, p[4]);
            fconv1->SetParameter(2, p[2]);
            
            hgaus->Fill(fgaus->Integral(-1000,10000));
            hconv1->Fill(fconv1->Integral(-1000,10000));
        }
        
        cout<<"integral error = "<<hgaus->GetStdDev()<<" and "<<hconv1->GetStdDev()<<endl;
        
        delete fgaus;
        delete fconv1;
        
        delete hgaus;
        delete hconv1;
    }
    delete hbg;
}