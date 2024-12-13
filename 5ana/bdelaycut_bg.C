{
//========= Macro generated from object: delaycut/Graph
//========= by ROOT version6.16/00
   
   TCutG *cutgbg = new TCutG("delaycutbg",10);
   cutgbg->SetVarX("bgt");
   cutgbg->SetVarY("bge");
   cutgbg->SetTitle("Graph");
   cutgbg->SetFillStyle(0);              // customized
   cutgbg->SetPoint(0,-50112.811,3000);
   cutgbg->SetPoint(1,-50142.606,490.4);
   cutgbg->SetPoint(2,-50150.054,270.964);
   cutgbg->SetPoint(3,-50224.539,171.042);
   cutgbg->SetPoint(4,-50343.716,88.7539);
   cutgbg->SetPoint(5,-50366.062,49.569);
   cutgbg->SetPoint(6,-50269.231,1.37148);
   cutgbg->SetPoint(7,-58000,6.46551);
   cutgbg->SetPoint(8,-58000,3000);
   cutgbg->SetPoint(9,-50112.811,3000);
   cutgbg->Draw("same");
}
