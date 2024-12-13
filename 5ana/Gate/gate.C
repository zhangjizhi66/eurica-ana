
TH2F *h2;
TCanvas *c1 = new TCanvas;

Int_t e,e1,e2;  // gate (e1,e2), name e
vector<int> b;  // background bin

void peaks(TH1 *h, Double_t res=1.5, Double_t thres=0.05, int npeaks=10)
{
    double x0 = h->GetBinLowEdge(h->GetNbinsX());
    double x1 = h->GetBinLowEdge(0);
    double ymin = h->GetBinContent(h->GetMinimumBin());
    double ymax = h->GetBinContent(h->GetMaximumBin())*1.3;
    if (ymin < 0 && ymin < -0.1*ymax) ymin = -0.1*ymax;//ymin=0.01; 
    //std::cout<< CYAN << ic << " " << icy << " " << h->GetName() <<"  ["<<h->GetTitle()<<"]"<<RESET<<std::endl;
    h->GetYaxis()->SetNoExponent();
    h->SetLineColor(kBlue);
    h->SetFillColorAlpha(kCyan,0.15);
    TSpectrum *s = new TSpectrum(1000);
    h->Sumw2(0);
    h->SetAxisRange(ymin, ymax, "Y");
    //h->SetStats(0);
    Int_t nfound = 0;
    Int_t nloop = 0;
    while(nloop < 1000){
        nfound = s->Search(h, res, "", thres);
        if(nfound > npeaks) thres += 0.0001;
        else thres -= 0.0001;
        if(thres < 0 || TMath::Abs(nfound-npeaks) < 3 ) break;
        nloop++;
    }
  
    TPolyMarker *pm = (TPolyMarker *)
                      h->GetListOfFunctions()->FindObject("TPolyMarker");
    pm->SetMarkerStyle(2);//32
    pm->SetMarkerColor(kRed);
    pm->SetMarkerSize(0.5);//0.4
    Double_t *xpeaks = s->GetPositionX();
    Double_t *ypeaks = s->GetPositionY();
    //to improve the accuracy of peak positions.
    // for(int i = 0; i < 1; i++) {
    for(int j = 0; j < nfound; j++) {
        int binx0 = h->FindBin(xpeaks[j]);
        if (binx0 > 1 && binx0 < h->GetNbinsX()) {
            float ymax = ypeaks[j];
            float ya = h->GetBinContent(binx0-1);
            float yb = h->GetBinContent(binx0+1);
            if(ymax < ya){
                xpeaks[j] = h->GetBinCenter(binx0-1);
                ypeaks[j] = ya;
                pm->SetPoint(j, xpeaks[j], ypeaks[j]);
            }
            if(ymax < yb){
                xpeaks[j] = h->GetBinCenter(binx0+1);
                ypeaks[j] = yb;
                pm->SetPoint(j, xpeaks[j], ypeaks[j]);    
            }
        }
    }
    // }
  
    if (1){
        // std::map<int, int> mg;
        for(int j = 0 ;j < nfound; j++) {
            std::stringstream ss;
            ss << xpeaks[j];
            if (ypeaks[j] < 3) continue;
            TString s1 = ss.str();
            TLatex *tex = new TLatex(xpeaks[j], ypeaks[j]+ymax*0.02, s1);
            tex->SetTextFont(133);//13
            tex->SetTextSize(16);
            tex->SetTextAlign(12);
            tex->SetTextAngle(90);
            tex->SetTextColor(kRed);
            tex->Draw();
            h->GetListOfFunctions()->Add(tex);
            // mg.insert(make_pair(xpeaks[j], ypeaks[j]));
        }
        pm->Draw();
    }
  
    TLine *l1 = new TLine(x0, 0, x1, 0);
    l1->SetLineColorAlpha(kRed, 0.7);
    l1->Draw();
    // please don't delete l1 !!!!
  
    c1->Draw();

    delete s;
}

void xgate()
{
    h2->ProjectionY(Form("h%d",e),e1+1,e2+1);
    TH1F *h = (TH1F*)gROOT->FindObject(Form("h%d",e));
    TH1F *hbg = new TH1F(Form("hbg%d",e),"hbg",h2->GetYaxis()->GetNbins(),0,h2->GetYaxis()->GetXmax());
    for (unsigned int i=0; i<b.size(); i++){
        h2->ProjectionY(Form("b%d",b[i]),b[i]+1,b[i]+1);
        TH1F *hbtemp = (TH1F*)gROOT->FindObject(Form("b%d",b[i]));
        hbg->Add(hbg,hbtemp,1,1);
    }
    double weight = (double)(e2-e1+1)/b.size();
    h->Add(h,hbg,1,-weight);
    peaks(h);
    //h->Draw();
    c1->Draw();
    delete hbg;
}

void ygate()
{
    h2->ProjectionX(Form("h%d",e),e1+1,e2+1);
    TH1F *h = (TH1F*)gROOT->FindObject(Form("h%d",e));
    TH1F *hbg = new TH1F(Form("hbg%d",e),"hbg",h2->GetXaxis()->GetNbins(),0,h2->GetXaxis()->GetXmax());
    for (unsigned int i=0; i<b.size(); i++){
        h2->ProjectionX(Form("b%d",b[i]),b[i]+1,b[i]+1);
        TH1F *hbtemp = (TH1F*)gROOT->FindObject(Form("b%d",b[i]));
        hbg->Add(hbg,hbtemp,1,1);
    }
    double weight = (double)(e2-e1+1)/b.size();
    h->Add(h,hbg,1,-weight);
    peaks(h);
    //h->Draw();
    c1->Draw();
    delete hbg;
}
