{
//========= Macro generated from object: delaycut/Graph
//========= by ROOT version6.16/00
   
   TCutG *cutg = new TCutG("delaycut",10);
   cutg->SetVarX("bgt");
   cutg->SetVarY("bge");
   cutg->SetTitle("Graph");
   cutg->SetFillStyle(0);              // customized
   cutg->SetPoint(0,-112.811,3000);
   cutg->SetPoint(1,-142.606,490.4);
   cutg->SetPoint(2,-150.054,270.964);
   cutg->SetPoint(3,-224.539,171.042);
   cutg->SetPoint(4,-343.716,88.7539);
   cutg->SetPoint(5,-366.062,49.569);
   cutg->SetPoint(6,-269.231,1.37148);
   cutg->SetPoint(7,-8000,6.46551);
   cutg->SetPoint(8,-8000,3000);
   cutg->SetPoint(9,-112.811,3000);
   cutg->Draw("same");
}
