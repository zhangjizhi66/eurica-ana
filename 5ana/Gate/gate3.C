
TH3I *h3;
TCanvas *c1 = new TCanvas;

Int_t e,e1,e2;  // gate (e1,e2), name e
vector<int> b;  // background bin

void xgate()
{
    h3->GetXaxis()->SetRange(e1+1,e2+1);
    h3->Project3D("yz");
    TH2D *h = (TH2D*)gROOT->FindObject(TString(h3->GetName())+TString("_yz"));
    h->SetName(Form("h%d",e));
    
    TH2D *hbg = new TH2D(Form("hbg%d",e),"hbg",h3->GetZaxis()->GetNbins(),h3->GetZaxis()->GetXmin(),h3->GetZaxis()->GetXmax(),h3->GetYaxis()->GetNbins(),h3->GetYaxis()->GetXmin(),h3->GetYaxis()->GetXmax());
    for (unsigned int i=0; i<b.size(); i++){
        h3->GetXaxis()->SetRange(b[i]+1,b[i]+1);
        h3->Project3D("yz");
        TH2D *hbtemp = (TH2D*)gROOT->FindObject(TString(h3->GetName())+TString("_yz"));
        hbtemp->SetName(Form("b%d",b[i]));
        hbg->Add(hbg,hbtemp,1,1);
    }
    double weight = (double)(e2-e1+1)/b.size();
    h->Add(h,hbg,1,-weight);
    
    h->Draw("colz");
    c1->Draw();
    delete hbg;
}
