simple node
{
    gates:
        input in;
        output out;
}

simple centralNode
{
    gates:
        input in1;
        input in2;
        input in3;
        input in4;
        input in5;
        input in6;
        input in7;
        input in8;
        input in9;

        output out1;
        output out2;
        output out3;
        output out4;
        output out5;
        output out6;
        output out7;
        output out8;
        output out9;
}

simple twoGateNode
{
    gates:
        input in1;
        input in2;

        output out1;
        output out2;
}

simple threeGateNode
{
    gates:
        input in1;
        input in2;
        input in3;

        output out1;
        output out2;
        output out3;
}

simple fourGateNode
{
    gates:
        input in1;
        input in2;
        input in3;
        input in4;

        output out1;
        output out2;
        output out3;
        output out4;
}



network star
{
    @display("bgb=339,247");
    submodules:
        A: centralNode {
            @display("p=161,127");
        }
        B: node {
            @display("p=135,18");
        }
        C: node {
            @display("p=239,18");
        }
        D: node {
            @display("p=298,69");
        }
        E: node {
            @display("p=305,127");
        }
        F: node {
            @display("p=314,192");
        }
        G: node {
            @display("p=154,204");
        }
        H: node {
            @display("p=36,184");
        }
        I: node {
            @display("p=36,114");
        }
        J: node {
            @display("p=36,42");
        }
    connections:
        A.out1 --> {  delay = 100ms; } --> B.in;
        A.out2 --> {  delay = 100ms; } --> C.in;
        A.out3 --> {  delay = 100ms; } --> D.in;
        A.out4 --> {  delay = 100ms; } --> E.in;
        A.out5 --> {  delay = 100ms; } --> F.in;
        A.out6 --> {  delay = 100ms; } --> G.in;
        A.out7 --> {  delay = 100ms; } --> H.in;
        A.out8 --> {  delay = 100ms; } --> I.in;
        A.out9 --> {  delay = 100ms; } --> J.in;

        B.out --> {  delay = 100ms; } --> A.in1;
        C.out --> {  delay = 100ms; } --> A.in2;
        D.out --> {  delay = 100ms; } --> A.in3;
        E.out --> {  delay = 100ms; } --> A.in4;
        F.out --> {  delay = 100ms; } --> A.in5;
        G.out --> {  delay = 100ms; } --> A.in6;
        H.out --> {  delay = 100ms; } --> A.in7;
        I.out --> {  delay = 100ms; } --> A.in8;
        J.out --> {  delay = 100ms; } --> A.in9;


}


network mesh
{
    submodules:
        A: twoGateNode {
            @display("p=57,76");
        }
        D: twoGateNode {
            @display("p=386,76");
        }
        I: twoGateNode {
            @display("p=57,221");
        }
        L: twoGateNode {
            @display("p=386,221");
        }
        F: fourGateNode {
            @display("p=168,150");
        }
        G: fourGateNode {
            @display("p=272,150");
        }
        B: threeGateNode {
            @display("p=168,76");
        }
        C: threeGateNode {
            @display("p=272,76");
        }
        E: threeGateNode {
            @display("p=57,150");
        }
        H: threeGateNode {
            @display("p=386,150");
        }
        J: threeGateNode {
            @display("p=168,221");
        }
        K: threeGateNode {
            @display("p=272,221");
        }
    connections:
        A.out1 --> {  delay = 100ms; } --> B.in1;
        A.out2 --> {  delay = 100ms; } --> E.in1;

        B.out1 --> {  delay = 100ms; } --> A.in1;
        B.out2 --> {  delay = 100ms; } --> C.in1;
        B.out3 --> {  delay = 100ms; } --> F.in1;

        C.out1 --> {  delay = 100ms; } --> B.in2;
        C.out2 --> {  delay = 100ms; } --> G.in1;
        C.out3 --> {  delay = 100ms; } --> D.in1;

        D.out1 --> {  delay = 100ms; } --> C.in2;
        D.out2 --> {  delay = 100ms; } --> H.in1;

        E.out1 --> {  delay = 100ms; } --> A.in2;
        E.out2 --> {  delay = 100ms; } --> F.in2;
        E.out3 --> {  delay = 100ms; } --> I.in1;

        F.out1 --> {  delay = 100ms; } --> B.in3;
        F.out2 --> {  delay = 100ms; } --> E.in2;
        F.out3 --> {  delay = 100ms; } --> G.in2;
        F.out4 --> {  delay = 100ms; } --> J.in1;

        G.out1 --> {  delay = 100ms; } --> F.in3;
        G.out2 --> {  delay = 100ms; } --> C.in3;
        G.out3 --> {  delay = 100ms; } --> H.in2;
        G.out4 --> {  delay = 100ms; } --> K.in1;

        H.out1 --> {  delay = 100ms; } --> D.in2;
        H.out2 --> {  delay = 100ms; } --> G.in3;
        H.out3 --> {  delay = 100ms; } --> L.in1;

        I.out1 --> {  delay = 100ms; } --> E.in3;
        I.out2 --> {  delay = 100ms; } --> J.in2;

        J.out1 --> {  delay = 100ms; } --> F.in4;
        J.out2 --> {  delay = 100ms; } --> I.in2;
        J.out3 --> {  delay = 100ms; } --> K.in2;

        K.out1 --> {  delay = 100ms; } --> G.in4;
        K.out2 --> {  delay = 100ms; } --> J.in3;
        K.out3 --> {  delay = 100ms; } --> L.in2;

        L.out1 --> {  delay = 100ms; } --> H.in3;
        L.out2 --> {  delay = 100ms; } --> K.in3;

}


