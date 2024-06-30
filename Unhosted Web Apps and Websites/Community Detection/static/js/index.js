function hovin(x){
    document.getElementById(x).style.scale = "1.2";
    document.getElementById(x).style.transitionDuration = "500ms";
}

function hovout(x){
    document.getElementById(x).style.scale = "1";
    document.getElementById(x).style.transitionDuration = "500ms";
}

function scr(x){
    document.getElementById(x).scrollIntoView();
}

function optview(x){
    if(x == 0){
        document.getElementById('f0').style.height = "50px";
        document.getElementById('f1').style.height = "0px";
        document.getElementById('f2').style.height = "50px";
        document.getElementById('f3').style.height = "50px";
        document.getElementById('p10').style.height = "28px";
        document.getElementById('f0').style.transitionDuration = "300ms";
        document.getElementById('f1').style.transitionDuration = "300ms";
        document.getElementById('f2').style.transitionDuration = "300ms";
        document.getElementById('f3').style.transitionDuration = "300ms";
        document.getElementById('p10').style.transitionDuration = "300ms";
    }
    else if(x == 1){
        document.getElementById('f0').style.height = "0px";
        document.getElementById('f1').style.height = "0px";
        document.getElementById('f2').style.height = "50px";
        document.getElementById('f3').style.height = "0px";
        document.getElementById('p10').style.height = "28px";
        document.getElementById('f0').style.transitionDuration = "300ms";
        document.getElementById('f1').style.transitionDuration = "300ms";
        document.getElementById('f2').style.transitionDuration = "300ms";
        document.getElementById('f3').style.transitionDuration = "300ms";
        document.getElementById('p10').style.transitionDuration = "300ms";
    }
    else if(x == 2){
        document.getElementById('f0').style.height = "0px";
        document.getElementById('f1').style.height = "50px";
        document.getElementById('f2').style.height = "0px";
        document.getElementById('f3').style.height = "50px";
        document.getElementById('p10').style.height = "28px";
        document.getElementById('f0').style.transitionDuration = "300ms";
        document.getElementById('f1').style.transitionDuration = "300ms";
        document.getElementById('f2').style.transitionDuration = "300ms";
        document.getElementById('f3').style.transitionDuration = "300ms";
        document.getElementById('p10').style.transitionDuration = "300ms";
    }
    else if(x == 3){
        document.getElementById('f0').style.height = "0px";
        document.getElementById('f1').style.height = "0px";
        document.getElementById('f2').style.height = "0px";
        document.getElementById('f3').style.height = "50px";
        document.getElementById('p10').style.height = "28px";
        document.getElementById('f0').style.transitionDuration = "300ms";
        document.getElementById('f1').style.transitionDuration = "300ms";
        document.getElementById('f2').style.transitionDuration = "300ms";
        document.getElementById('f3').style.transitionDuration = "300ms";
        document.getElementById('p10').style.transitionDuration = "300ms";
    }
    else if(x == 4){
        document.getElementById('f0').style.height = "0px";
        document.getElementById('f1').style.height = "50px";
        document.getElementById('f2').style.height = "50px";
        document.getElementById('f3').style.height = "0px";
        document.getElementById('p10').style.height = "28px";
        document.getElementById('f0').style.transitionDuration = "300ms";
        document.getElementById('f1').style.transitionDuration = "300ms";
        document.getElementById('f2').style.transitionDuration = "300ms";
        document.getElementById('f3').style.transitionDuration = "300ms";
        document.getElementById('p10').style.transitionDuration = "300ms";
    }
    else if(x == 5){
        document.getElementById('f0').style.height = "50px";
        document.getElementById('f1').style.height = "0px";
        document.getElementById('f2').style.height = "0px";
        document.getElementById('f3').style.height = "0px";
        document.getElementById('p10').style.height = "28px";
        document.getElementById('f0').style.transitionDuration = "300ms";
        document.getElementById('f1').style.transitionDuration = "300ms";
        document.getElementById('f2').style.transitionDuration = "300ms";
        document.getElementById('f3').style.transitionDuration = "300ms";
        document.getElementById('p10').style.transitionDuration = "300ms";
    }
    else if(x == 6){
        document.getElementById('f0').style.height = "50px";
        document.getElementById('f1').style.height = "50px";
        document.getElementById('f2').style.height = "50px";
        document.getElementById('f3').style.height = "50px";
        document.getElementById('p10').style.height = "28px";
        document.getElementById('f0').style.transitionDuration = "300ms";
        document.getElementById('f1').style.transitionDuration = "300ms";
        document.getElementById('f2').style.transitionDuration = "300ms";
        document.getElementById('f3').style.transitionDuration = "300ms";
        document.getElementById('p10').style.transitionDuration = "300ms";
    }
}

var checker1 = 0;

function gof(){
    checker1 = (checker1+1)%10;
    if(checker1 == 0){
        document.getElementById("panel1").style.width = "1281px";
        document.getElementById("panel1").style.padding = "50px";
        document.getElementById("panel2").style.width = "0px";
        document.getElementById("panel2").style.padding = "0px";
        document.getElementById("panel3").style.width = "0px";
        document.getElementById("panel3").style.padding = "0px";
        document.getElementById("panel4").style.width = "0px";
        document.getElementById("panel4").style.padding = "0px";
        document.getElementById("panel5").style.width = "0px";
        document.getElementById("panel5").style.padding = "0px";
        document.getElementById("panel6").style.width = "0px";
        document.getElementById("panel6").style.padding = "0px";
        document.getElementById("panel7").style.width = "0px";
        document.getElementById("panel7").style.padding = "0px";
        document.getElementById("panel8").style.width = "0px";
        document.getElementById("panel8").style.padding = "0px";
        document.getElementById("panel9").style.width = "0px";
        document.getElementById("panel9").style.padding = "0px";
        document.getElementById("panel10").style.width = "0px";
        document.getElementById("panel10").style.padding = "0px";
    }
    else if(checker1 == 1){
        document.getElementById("panel1").style.width = "0px";
        document.getElementById("panel1").style.padding = "0px";
        document.getElementById("panel2").style.width = "1281px";
        document.getElementById("panel2").style.padding = "50px";
        document.getElementById("panel3").style.width = "0px";
        document.getElementById("panel3").style.padding = "0px";
        document.getElementById("panel4").style.width = "0px";
        document.getElementById("panel4").style.padding = "0px";
        document.getElementById("panel5").style.width = "0px";
        document.getElementById("panel5").style.padding = "0px";
        document.getElementById("panel6").style.width = "0px";
        document.getElementById("panel6").style.padding = "0px";
        document.getElementById("panel7").style.width = "0px";
        document.getElementById("panel7").style.padding = "0px";
        document.getElementById("panel8").style.width = "0px";
        document.getElementById("panel8").style.padding = "0px";
        document.getElementById("panel9").style.width = "0px";
        document.getElementById("panel9").style.padding = "0px";
        document.getElementById("panel10").style.width = "0px";
        document.getElementById("panel10").style.padding = "0px";
    }
    else if(checker1 == 2){
        document.getElementById("panel1").style.width = "0px";
        document.getElementById("panel1").style.padding = "0px";
        document.getElementById("panel2").style.width = "0px";
        document.getElementById("panel2").style.padding = "0px";
        document.getElementById("panel3").style.width = "1281px";
        document.getElementById("panel3").style.padding = "50px";
        document.getElementById("panel4").style.width = "0px";
        document.getElementById("panel4").style.padding = "0px";
        document.getElementById("panel5").style.width = "0px";
        document.getElementById("panel5").style.padding = "0px";
        document.getElementById("panel6").style.width = "0px";
        document.getElementById("panel6").style.padding = "0px";
        document.getElementById("panel7").style.width = "0px";
        document.getElementById("panel7").style.padding = "0px";
        document.getElementById("panel8").style.width = "0px";
        document.getElementById("panel8").style.padding = "0px";
        document.getElementById("panel9").style.width = "0px";
        document.getElementById("panel9").style.padding = "0px";
        document.getElementById("panel10").style.width = "0px";
        document.getElementById("panel10").style.padding = "0px";
    }
    else if(checker1 == 3){
        document.getElementById("panel1").style.width = "0px";
        document.getElementById("panel1").style.padding = "0px";
        document.getElementById("panel2").style.width = "0px";
        document.getElementById("panel2").style.padding = "0px";
        document.getElementById("panel3").style.width = "0px";
        document.getElementById("panel3").style.padding = "0px";
        document.getElementById("panel4").style.width = "1281px";
        document.getElementById("panel4").style.padding = "50px";
        document.getElementById("panel5").style.width = "0px";
        document.getElementById("panel5").style.padding = "0px";
        document.getElementById("panel6").style.width = "0px";
        document.getElementById("panel6").style.padding = "0px";
        document.getElementById("panel7").style.width = "0px";
        document.getElementById("panel7").style.padding = "0px";
        document.getElementById("panel8").style.width = "0px";
        document.getElementById("panel8").style.padding = "0px";
        document.getElementById("panel9").style.width = "0px";
        document.getElementById("panel9").style.padding = "0px";
        document.getElementById("panel10").style.width = "0px";
        document.getElementById("panel10").style.padding = "0px";
    }
    else if(checker1 == 4){
        document.getElementById("panel1").style.width = "0px";
        document.getElementById("panel1").style.padding = "0px";
        document.getElementById("panel2").style.width = "0px";
        document.getElementById("panel2").style.padding = "0px";
        document.getElementById("panel3").style.width = "0px";
        document.getElementById("panel3").style.padding = "0px";
        document.getElementById("panel4").style.width = "0px";
        document.getElementById("panel4").style.padding = "0px";
        document.getElementById("panel5").style.width = "1281px";
        document.getElementById("panel5").style.padding = "50px";
        document.getElementById("panel6").style.width = "0px";
        document.getElementById("panel6").style.padding = "0px";
        document.getElementById("panel7").style.width = "0px";
        document.getElementById("panel7").style.padding = "0px";
        document.getElementById("panel8").style.width = "0px";
        document.getElementById("panel8").style.padding = "0px";
        document.getElementById("panel9").style.width = "0px";
        document.getElementById("panel9").style.padding = "0px";
        document.getElementById("panel10").style.width = "0px";
        document.getElementById("panel10").style.padding = "0px";
    }
    else if(checker1 == 5){
        document.getElementById("panel1").style.width = "0px";
        document.getElementById("panel1").style.padding = "0px";
        document.getElementById("panel2").style.width = "0px";
        document.getElementById("panel2").style.padding = "0px";
        document.getElementById("panel3").style.width = "0px";
        document.getElementById("panel3").style.padding = "0px";
        document.getElementById("panel4").style.width = "0px";
        document.getElementById("panel4").style.padding = "0px";
        document.getElementById("panel5").style.width = "0px";
        document.getElementById("panel5").style.padding = "0px";
        document.getElementById("panel6").style.width = "1281px";
        document.getElementById("panel6").style.padding = "50px";
        document.getElementById("panel7").style.width = "0px";
        document.getElementById("panel7").style.padding = "0px";
        document.getElementById("panel8").style.width = "0px";
        document.getElementById("panel8").style.padding = "0px";
        document.getElementById("panel9").style.width = "0px";
        document.getElementById("panel9").style.padding = "0px";
        document.getElementById("panel10").style.width = "0px";
        document.getElementById("panel10").style.padding = "0px";
    }
    else if(checker1 == 6){
        document.getElementById("panel1").style.width = "0px";
        document.getElementById("panel1").style.padding = "0px";
        document.getElementById("panel2").style.width = "0px";
        document.getElementById("panel2").style.padding = "0px";
        document.getElementById("panel3").style.width = "0px";
        document.getElementById("panel3").style.padding = "0px";
        document.getElementById("panel4").style.width = "0px";
        document.getElementById("panel4").style.padding = "0px";
        document.getElementById("panel5").style.width = "0px";
        document.getElementById("panel5").style.padding = "0px";
        document.getElementById("panel6").style.width = "0px";
        document.getElementById("panel6").style.padding = "0px";
        document.getElementById("panel7").style.width = "1281px";
        document.getElementById("panel7").style.padding = "50px";
        document.getElementById("panel8").style.width = "0px";
        document.getElementById("panel8").style.padding = "0px";
        document.getElementById("panel9").style.width = "0px";
        document.getElementById("panel9").style.padding = "0px";
        document.getElementById("panel10").style.width = "0px";
        document.getElementById("panel10").style.padding = "0px";
    }
    else if(checker1 == 7){
        document.getElementById("panel1").style.width = "0px";
        document.getElementById("panel1").style.padding = "0px";
        document.getElementById("panel2").style.width = "0px";
        document.getElementById("panel2").style.padding = "0px";
        document.getElementById("panel3").style.width = "0px";
        document.getElementById("panel3").style.padding = "0px";
        document.getElementById("panel4").style.width = "0px";
        document.getElementById("panel4").style.padding = "0px";
        document.getElementById("panel5").style.width = "0px";
        document.getElementById("panel5").style.padding = "0px";
        document.getElementById("panel6").style.width = "0px";
        document.getElementById("panel6").style.padding = "0px";
        document.getElementById("panel7").style.width = "0px";
        document.getElementById("panel7").style.padding = "0px";
        document.getElementById("panel8").style.width = "1281px";
        document.getElementById("panel8").style.padding = "50px";
        document.getElementById("panel9").style.width = "0px";
        document.getElementById("panel9").style.padding = "0px";
        document.getElementById("panel10").style.width = "0px";
        document.getElementById("panel10").style.padding = "0px";
    }
    else if(checker1 == 8){
        document.getElementById("panel1").style.width = "0px";
        document.getElementById("panel1").style.padding = "0px";
        document.getElementById("panel2").style.width = "0px";
        document.getElementById("panel2").style.padding = "0px";
        document.getElementById("panel3").style.width = "0px";
        document.getElementById("panel3").style.padding = "0px";
        document.getElementById("panel4").style.width = "0px";
        document.getElementById("panel4").style.padding = "0px";
        document.getElementById("panel5").style.width = "0px";
        document.getElementById("panel5").style.padding = "0px";
        document.getElementById("panel6").style.width = "0px";
        document.getElementById("panel6").style.padding = "0px";
        document.getElementById("panel7").style.width = "0px";
        document.getElementById("panel7").style.padding = "0px";
        document.getElementById("panel8").style.width = "0px";
        document.getElementById("panel8").style.padding = "0px";
        document.getElementById("panel9").style.width = "1281px";
        document.getElementById("panel9").style.padding = "50px";
        document.getElementById("panel10").style.width = "0px";
        document.getElementById("panel10").style.padding = "0px";
    }
    else if(checker1 == 9){
        document.getElementById("panel1").style.width = "0px";
        document.getElementById("panel1").style.padding = "0px";
        document.getElementById("panel2").style.width = "0px";
        document.getElementById("panel2").style.padding = "0px";
        document.getElementById("panel3").style.width = "0px";
        document.getElementById("panel3").style.padding = "0px";
        document.getElementById("panel4").style.width = "0px";
        document.getElementById("panel4").style.padding = "0px";
        document.getElementById("panel5").style.width = "0px";
        document.getElementById("panel5").style.padding = "0px";
        document.getElementById("panel6").style.width = "0px";
        document.getElementById("panel6").style.padding = "0px";
        document.getElementById("panel7").style.width = "0px";
        document.getElementById("panel7").style.padding = "0px";
        document.getElementById("panel8").style.width = "0px";
        document.getElementById("panel8").style.padding = "0px";
        document.getElementById("panel9").style.width = "0px";
        document.getElementById("panel9").style.padding = "0px";
        document.getElementById("panel10").style.width = "1281px";
        document.getElementById("panel10").style.padding = "50px";
    }
    document.getElementById("panel1").style.transitionDuration = "300ms";
    document.getElementById("panel2").style.transitionDuration = "300ms";
    document.getElementById("panel3").style.transitionDuration = "300ms";
    document.getElementById("panel4").style.transitionDuration = "300ms";
    document.getElementById("panel5").style.transitionDuration = "300ms";
    document.getElementById("panel6").style.transitionDuration = "300ms";
    document.getElementById("panel7").style.transitionDuration = "300ms";
    document.getElementById("panel8").style.transitionDuration = "300ms";
    document.getElementById("panel9").style.transitionDuration = "300ms";
    document.getElementById("panel10").style.transitionDuration = "300ms";
}

function gob(){
    checker1 = (checker1-1+10)%10;
    if(checker1 == 0){
        document.getElementById("panel1").style.width = "1281px";
        document.getElementById("panel1").style.padding = "50px";
        document.getElementById("panel2").style.width = "0px";
        document.getElementById("panel2").style.padding = "0px";
        document.getElementById("panel3").style.width = "0px";
        document.getElementById("panel3").style.padding = "0px";
        document.getElementById("panel4").style.width = "0px";
        document.getElementById("panel4").style.padding = "0px";
        document.getElementById("panel5").style.width = "0px";
        document.getElementById("panel5").style.padding = "0px";
        document.getElementById("panel6").style.width = "0px";
        document.getElementById("panel6").style.padding = "0px";
        document.getElementById("panel7").style.width = "0px";
        document.getElementById("panel7").style.padding = "0px";
        document.getElementById("panel8").style.width = "0px";
        document.getElementById("panel8").style.padding = "0px";
        document.getElementById("panel9").style.width = "0px";
        document.getElementById("panel9").style.padding = "0px";
        document.getElementById("panel10").style.width = "0px";
        document.getElementById("panel10").style.padding = "0px";
    }
    else if(checker1 == 1){
        document.getElementById("panel1").style.width = "0px";
        document.getElementById("panel1").style.padding = "0px";
        document.getElementById("panel2").style.width = "1281px";
        document.getElementById("panel2").style.padding = "50px";
        document.getElementById("panel3").style.width = "0px";
        document.getElementById("panel3").style.padding = "0px";
        document.getElementById("panel4").style.width = "0px";
        document.getElementById("panel4").style.padding = "0px";
        document.getElementById("panel5").style.width = "0px";
        document.getElementById("panel5").style.padding = "0px";
        document.getElementById("panel6").style.width = "0px";
        document.getElementById("panel6").style.padding = "0px";
        document.getElementById("panel7").style.width = "0px";
        document.getElementById("panel7").style.padding = "0px";
        document.getElementById("panel8").style.width = "0px";
        document.getElementById("panel8").style.padding = "0px";
        document.getElementById("panel9").style.width = "0px";
        document.getElementById("panel9").style.padding = "0px";
        document.getElementById("panel10").style.width = "0px";
        document.getElementById("panel10").style.padding = "0px";
    }
    else if(checker1 == 2){
        document.getElementById("panel1").style.width = "0px";
        document.getElementById("panel1").style.padding = "0px";
        document.getElementById("panel2").style.width = "0px";
        document.getElementById("panel2").style.padding = "0px";
        document.getElementById("panel3").style.width = "1281px";
        document.getElementById("panel3").style.padding = "50px";
        document.getElementById("panel4").style.width = "0px";
        document.getElementById("panel4").style.padding = "0px";
        document.getElementById("panel5").style.width = "0px";
        document.getElementById("panel5").style.padding = "0px";
        document.getElementById("panel6").style.width = "0px";
        document.getElementById("panel6").style.padding = "0px";
        document.getElementById("panel7").style.width = "0px";
        document.getElementById("panel7").style.padding = "0px";
        document.getElementById("panel8").style.width = "0px";
        document.getElementById("panel8").style.padding = "0px";
        document.getElementById("panel9").style.width = "0px";
        document.getElementById("panel9").style.padding = "0px";
        document.getElementById("panel10").style.width = "0px";
        document.getElementById("panel10").style.padding = "0px";
    }
    else if(checker1 == 3){
        document.getElementById("panel1").style.width = "0px";
        document.getElementById("panel1").style.padding = "0px";
        document.getElementById("panel2").style.width = "0px";
        document.getElementById("panel2").style.padding = "0px";
        document.getElementById("panel3").style.width = "0px";
        document.getElementById("panel3").style.padding = "0px";
        document.getElementById("panel4").style.width = "1281px";
        document.getElementById("panel4").style.padding = "50px";
        document.getElementById("panel5").style.width = "0px";
        document.getElementById("panel5").style.padding = "0px";
        document.getElementById("panel6").style.width = "0px";
        document.getElementById("panel6").style.padding = "0px";
        document.getElementById("panel7").style.width = "0px";
        document.getElementById("panel7").style.padding = "0px";
        document.getElementById("panel8").style.width = "0px";
        document.getElementById("panel8").style.padding = "0px";
        document.getElementById("panel9").style.width = "0px";
        document.getElementById("panel9").style.padding = "0px";
        document.getElementById("panel10").style.width = "0px";
        document.getElementById("panel10").style.padding = "0px";
    }
    else if(checker1 == 4){
        document.getElementById("panel1").style.width = "0px";
        document.getElementById("panel1").style.padding = "0px";
        document.getElementById("panel2").style.width = "0px";
        document.getElementById("panel2").style.padding = "0px";
        document.getElementById("panel3").style.width = "0px";
        document.getElementById("panel3").style.padding = "0px";
        document.getElementById("panel4").style.width = "0px";
        document.getElementById("panel4").style.padding = "0px";
        document.getElementById("panel5").style.width = "1281px";
        document.getElementById("panel5").style.padding = "50px";
        document.getElementById("panel6").style.width = "0px";
        document.getElementById("panel6").style.padding = "0px";
        document.getElementById("panel7").style.width = "0px";
        document.getElementById("panel7").style.padding = "0px";
        document.getElementById("panel8").style.width = "0px";
        document.getElementById("panel8").style.padding = "0px";
        document.getElementById("panel9").style.width = "0px";
        document.getElementById("panel9").style.padding = "0px";
        document.getElementById("panel10").style.width = "0px";
        document.getElementById("panel10").style.padding = "0px";
    }
    else if(checker1 == 5){
        document.getElementById("panel1").style.width = "0px";
        document.getElementById("panel1").style.padding = "0px";
        document.getElementById("panel2").style.width = "0px";
        document.getElementById("panel2").style.padding = "0px";
        document.getElementById("panel3").style.width = "0px";
        document.getElementById("panel3").style.padding = "0px";
        document.getElementById("panel4").style.width = "0px";
        document.getElementById("panel4").style.padding = "0px";
        document.getElementById("panel5").style.width = "0px";
        document.getElementById("panel5").style.padding = "0px";
        document.getElementById("panel6").style.width = "1281px";
        document.getElementById("panel6").style.padding = "50px";
        document.getElementById("panel7").style.width = "0px";
        document.getElementById("panel7").style.padding = "0px";
        document.getElementById("panel8").style.width = "0px";
        document.getElementById("panel8").style.padding = "0px";
        document.getElementById("panel9").style.width = "0px";
        document.getElementById("panel9").style.padding = "0px";
        document.getElementById("panel10").style.width = "0px";
        document.getElementById("panel10").style.padding = "0px";
    }
    else if(checker1 == 6){
        document.getElementById("panel1").style.width = "0px";
        document.getElementById("panel1").style.padding = "0px";
        document.getElementById("panel2").style.width = "0px";
        document.getElementById("panel2").style.padding = "0px";
        document.getElementById("panel3").style.width = "0px";
        document.getElementById("panel3").style.padding = "0px";
        document.getElementById("panel4").style.width = "0px";
        document.getElementById("panel4").style.padding = "0px";
        document.getElementById("panel5").style.width = "0px";
        document.getElementById("panel5").style.padding = "0px";
        document.getElementById("panel6").style.width = "0px";
        document.getElementById("panel6").style.padding = "0px";
        document.getElementById("panel7").style.width = "1281px";
        document.getElementById("panel7").style.padding = "50px";
        document.getElementById("panel8").style.width = "0px";
        document.getElementById("panel8").style.padding = "0px";
        document.getElementById("panel9").style.width = "0px";
        document.getElementById("panel9").style.padding = "0px";
        document.getElementById("panel10").style.width = "0px";
        document.getElementById("panel10").style.padding = "0px";
    }
    else if(checker1 == 7){
        document.getElementById("panel1").style.width = "0px";
        document.getElementById("panel1").style.padding = "0px";
        document.getElementById("panel2").style.width = "0px";
        document.getElementById("panel2").style.padding = "0px";
        document.getElementById("panel3").style.width = "0px";
        document.getElementById("panel3").style.padding = "0px";
        document.getElementById("panel4").style.width = "0px";
        document.getElementById("panel4").style.padding = "0px";
        document.getElementById("panel5").style.width = "0px";
        document.getElementById("panel5").style.padding = "0px";
        document.getElementById("panel6").style.width = "0px";
        document.getElementById("panel6").style.padding = "0px";
        document.getElementById("panel7").style.width = "0px";
        document.getElementById("panel7").style.padding = "0px";
        document.getElementById("panel8").style.width = "1281px";
        document.getElementById("panel8").style.padding = "50px";
        document.getElementById("panel9").style.width = "0px";
        document.getElementById("panel9").style.padding = "0px";
        document.getElementById("panel10").style.width = "0px";
        document.getElementById("panel10").style.padding = "0px";
    }
    else if(checker1 == 8){
        document.getElementById("panel1").style.width = "0px";
        document.getElementById("panel1").style.padding = "0px";
        document.getElementById("panel2").style.width = "0px";
        document.getElementById("panel2").style.padding = "0px";
        document.getElementById("panel3").style.width = "0px";
        document.getElementById("panel3").style.padding = "0px";
        document.getElementById("panel4").style.width = "0px";
        document.getElementById("panel4").style.padding = "0px";
        document.getElementById("panel5").style.width = "0px";
        document.getElementById("panel5").style.padding = "0px";
        document.getElementById("panel6").style.width = "0px";
        document.getElementById("panel6").style.padding = "0px";
        document.getElementById("panel7").style.width = "0px";
        document.getElementById("panel7").style.padding = "0px";
        document.getElementById("panel8").style.width = "0px";
        document.getElementById("panel8").style.padding = "0px";
        document.getElementById("panel9").style.width = "1281px";
        document.getElementById("panel9").style.padding = "50px";
        document.getElementById("panel10").style.width = "0px";
        document.getElementById("panel10").style.padding = "0px";
    }
    else if(checker1 == 9){
        document.getElementById("panel1").style.width = "0px";
        document.getElementById("panel1").style.padding = "0px";
        document.getElementById("panel2").style.width = "0px";
        document.getElementById("panel2").style.padding = "0px";
        document.getElementById("panel3").style.width = "0px";
        document.getElementById("panel3").style.padding = "0px";
        document.getElementById("panel4").style.width = "0px";
        document.getElementById("panel4").style.padding = "0px";
        document.getElementById("panel5").style.width = "0px";
        document.getElementById("panel5").style.padding = "0px";
        document.getElementById("panel6").style.width = "0px";
        document.getElementById("panel6").style.padding = "0px";
        document.getElementById("panel7").style.width = "0px";
        document.getElementById("panel7").style.padding = "0px";
        document.getElementById("panel8").style.width = "0px";
        document.getElementById("panel8").style.padding = "0px";
        document.getElementById("panel9").style.width = "0px";
        document.getElementById("panel9").style.padding = "0px";
        document.getElementById("panel10").style.width = "1281px";
        document.getElementById("panel10").style.padding = "50px";
    }
    document.getElementById("panel1").style.transitionDuration = "300ms";
    document.getElementById("panel2").style.transitionDuration = "300ms";
    document.getElementById("panel3").style.transitionDuration = "300ms";
    document.getElementById("panel4").style.transitionDuration = "300ms";
    document.getElementById("panel5").style.transitionDuration = "300ms";
    document.getElementById("panel6").style.transitionDuration = "300ms";
    document.getElementById("panel7").style.transitionDuration = "300ms";
    document.getElementById("panel8").style.transitionDuration = "300ms";
    document.getElementById("panel9").style.transitionDuration = "300ms";
    document.getElementById("panel10").style.transitionDuration = "300ms";
}

var checker2 = 0;

function gof1(){
    checker2 = (checker2+1)%10;
    if(checker2 == 0){
        document.getElementById("panel11").style.width = "1281px";
        document.getElementById("panel11").style.padding = "50px";
        document.getElementById("panel12").style.width = "0px";
        document.getElementById("panel12").style.padding = "0px";
        document.getElementById("panel13").style.width = "0px";
        document.getElementById("panel13").style.padding = "0px";
        document.getElementById("panel14").style.width = "0px";
        document.getElementById("panel14").style.padding = "0px";
        document.getElementById("panel15").style.width = "0px";
        document.getElementById("panel15").style.padding = "0px";
        document.getElementById("panel16").style.width = "0px";
        document.getElementById("panel16").style.padding = "0px";
        document.getElementById("panel17").style.width = "0px";
        document.getElementById("panel17").style.padding = "0px";
        document.getElementById("panel18").style.width = "0px";
        document.getElementById("panel18").style.padding = "0px";
        document.getElementById("panel19").style.width = "0px";
        document.getElementById("panel19").style.padding = "0px";
        document.getElementById("panel20").style.width = "0px";
        document.getElementById("panel20").style.padding = "0px";
    }
    else if(checker2 == 1){
        document.getElementById("panel11").style.width = "0px";
        document.getElementById("panel11").style.padding = "0px";
        document.getElementById("panel12").style.width = "1281px";
        document.getElementById("panel12").style.padding = "50px";
        document.getElementById("panel13").style.width = "0px";
        document.getElementById("panel13").style.padding = "0px";
        document.getElementById("panel14").style.width = "0px";
        document.getElementById("panel14").style.padding = "0px";
        document.getElementById("panel15").style.width = "0px";
        document.getElementById("panel15").style.padding = "0px";
        document.getElementById("panel16").style.width = "0px";
        document.getElementById("panel16").style.padding = "0px";
        document.getElementById("panel17").style.width = "0px";
        document.getElementById("panel17").style.padding = "0px";
        document.getElementById("panel18").style.width = "0px";
        document.getElementById("panel18").style.padding = "0px";
        document.getElementById("panel19").style.width = "0px";
        document.getElementById("panel19").style.padding = "0px";
        document.getElementById("panel20").style.width = "0px";
        document.getElementById("panel20").style.padding = "0px";
    }
    else if(checker2 == 2){
        document.getElementById("panel11").style.width = "0px";
        document.getElementById("panel11").style.padding = "0px";
        document.getElementById("panel12").style.width = "0px";
        document.getElementById("panel12").style.padding = "0px";
        document.getElementById("panel13").style.width = "1281px";
        document.getElementById("panel13").style.padding = "50px";
        document.getElementById("panel14").style.width = "0px";
        document.getElementById("panel14").style.padding = "0px";
        document.getElementById("panel15").style.width = "0px";
        document.getElementById("panel15").style.padding = "0px";
        document.getElementById("panel16").style.width = "0px";
        document.getElementById("panel16").style.padding = "0px";
        document.getElementById("panel17").style.width = "0px";
        document.getElementById("panel17").style.padding = "0px";
        document.getElementById("panel18").style.width = "0px";
        document.getElementById("panel18").style.padding = "0px";
        document.getElementById("panel19").style.width = "0px";
        document.getElementById("panel19").style.padding = "0px";
        document.getElementById("panel10").style.width = "0px";
        document.getElementById("panel10").style.padding = "0px";
    }
    else if(checker2 == 3){
        document.getElementById("panel11").style.width = "0px";
        document.getElementById("panel11").style.padding = "0px";
        document.getElementById("panel12").style.width = "0px";
        document.getElementById("panel12").style.padding = "0px";
        document.getElementById("panel13").style.width = "0px";
        document.getElementById("panel13").style.padding = "0px";
        document.getElementById("panel14").style.width = "1281px";
        document.getElementById("panel14").style.padding = "50px";
        document.getElementById("panel15").style.width = "0px";
        document.getElementById("panel15").style.padding = "0px";
        document.getElementById("panel16").style.width = "0px";
        document.getElementById("panel16").style.padding = "0px";
        document.getElementById("panel17").style.width = "0px";
        document.getElementById("panel17").style.padding = "0px";
        document.getElementById("panel18").style.width = "0px";
        document.getElementById("panel18").style.padding = "0px";
        document.getElementById("panel19").style.width = "0px";
        document.getElementById("panel19").style.padding = "0px";
        document.getElementById("panel20").style.width = "0px";
        document.getElementById("panel20").style.padding = "0px";
    }
    else if(checker2 == 4){
        document.getElementById("panel11").style.width = "0px";
        document.getElementById("panel11").style.padding = "0px";
        document.getElementById("panel12").style.width = "0px";
        document.getElementById("panel12").style.padding = "0px";
        document.getElementById("panel13").style.width = "0px";
        document.getElementById("panel13").style.padding = "0px";
        document.getElementById("panel14").style.width = "0px";
        document.getElementById("panel14").style.padding = "0px";
        document.getElementById("panel15").style.width = "1281px";
        document.getElementById("panel15").style.padding = "50px";
        document.getElementById("panel16").style.width = "0px";
        document.getElementById("panel16").style.padding = "0px";
        document.getElementById("panel17").style.width = "0px";
        document.getElementById("panel17").style.padding = "0px";
        document.getElementById("panel18").style.width = "0px";
        document.getElementById("panel18").style.padding = "0px";
        document.getElementById("panel19").style.width = "0px";
        document.getElementById("panel19").style.padding = "0px";
        document.getElementById("panel20").style.width = "0px";
        document.getElementById("panel20").style.padding = "0px";
    }
    else if(checker2 == 5){
        document.getElementById("panel11").style.width = "0px";
        document.getElementById("panel11").style.padding = "0px";
        document.getElementById("panel12").style.width = "0px";
        document.getElementById("panel12").style.padding = "0px";
        document.getElementById("panel13").style.width = "0px";
        document.getElementById("panel13").style.padding = "0px";
        document.getElementById("panel14").style.width = "0px";
        document.getElementById("panel14").style.padding = "0px";
        document.getElementById("panel15").style.width = "0px";
        document.getElementById("panel15").style.padding = "0px";
        document.getElementById("panel16").style.width = "1281px";
        document.getElementById("panel16").style.padding = "50px";
        document.getElementById("panel17").style.width = "0px";
        document.getElementById("panel17").style.padding = "0px";
        document.getElementById("panel18").style.width = "0px";
        document.getElementById("panel18").style.padding = "0px";
        document.getElementById("panel19").style.width = "0px";
        document.getElementById("panel19").style.padding = "0px";
        document.getElementById("panel20").style.width = "0px";
        document.getElementById("panel20").style.padding = "0px";
    }
    else if(checker2 == 6){
        document.getElementById("panel11").style.width = "0px";
        document.getElementById("panel11").style.padding = "0px";
        document.getElementById("panel12").style.width = "0px";
        document.getElementById("panel12").style.padding = "0px";
        document.getElementById("panel13").style.width = "0px";
        document.getElementById("panel13").style.padding = "0px";
        document.getElementById("panel14").style.width = "0px";
        document.getElementById("panel14").style.padding = "0px";
        document.getElementById("panel15").style.width = "0px";
        document.getElementById("panel15").style.padding = "0px";
        document.getElementById("panel16").style.width = "0px";
        document.getElementById("panel16").style.padding = "0px";
        document.getElementById("panel17").style.width = "1281px";
        document.getElementById("panel17").style.padding = "50px";
        document.getElementById("panel18").style.width = "0px";
        document.getElementById("panel18").style.padding = "0px";
        document.getElementById("panel19").style.width = "0px";
        document.getElementById("panel19").style.padding = "0px";
        document.getElementById("panel20").style.width = "0px";
        document.getElementById("panel20").style.padding = "0px";
    }
    else if(checker2 == 7){
        document.getElementById("panel11").style.width = "0px";
        document.getElementById("panel11").style.padding = "0px";
        document.getElementById("panel12").style.width = "0px";
        document.getElementById("panel12").style.padding = "0px";
        document.getElementById("panel13").style.width = "0px";
        document.getElementById("panel13").style.padding = "0px";
        document.getElementById("panel14").style.width = "0px";
        document.getElementById("panel14").style.padding = "0px";
        document.getElementById("panel15").style.width = "0px";
        document.getElementById("panel15").style.padding = "0px";
        document.getElementById("panel16").style.width = "0px";
        document.getElementById("panel16").style.padding = "0px";
        document.getElementById("panel17").style.width = "0px";
        document.getElementById("panel17").style.padding = "0px";
        document.getElementById("panel18").style.width = "1281px";
        document.getElementById("panel18").style.padding = "50px";
        document.getElementById("panel19").style.width = "0px";
        document.getElementById("panel19").style.padding = "0px";
        document.getElementById("panel20").style.width = "0px";
        document.getElementById("panel20").style.padding = "0px";
    }
    else if(checker2 == 8){
        document.getElementById("panel11").style.width = "0px";
        document.getElementById("panel11").style.padding = "0px";
        document.getElementById("panel12").style.width = "0px";
        document.getElementById("panel12").style.padding = "0px";
        document.getElementById("panel13").style.width = "0px";
        document.getElementById("panel13").style.padding = "0px";
        document.getElementById("panel14").style.width = "0px";
        document.getElementById("panel14").style.padding = "0px";
        document.getElementById("panel15").style.width = "0px";
        document.getElementById("panel15").style.padding = "0px";
        document.getElementById("panel16").style.width = "0px";
        document.getElementById("panel16").style.padding = "0px";
        document.getElementById("panel17").style.width = "0px";
        document.getElementById("panel17").style.padding = "0px";
        document.getElementById("panel18").style.width = "0px";
        document.getElementById("panel18").style.padding = "0px";
        document.getElementById("panel19").style.width = "1281px";
        document.getElementById("panel19").style.padding = "50px";
        document.getElementById("panel20").style.width = "0px";
        document.getElementById("panel20").style.padding = "0px";
    }
    else if(checker2 == 9){
        document.getElementById("panel11").style.width = "0px";
        document.getElementById("panel11").style.padding = "0px";
        document.getElementById("panel12").style.width = "0px";
        document.getElementById("panel12").style.padding = "0px";
        document.getElementById("panel13").style.width = "0px";
        document.getElementById("panel13").style.padding = "0px";
        document.getElementById("panel14").style.width = "0px";
        document.getElementById("panel14").style.padding = "0px";
        document.getElementById("panel15").style.width = "0px";
        document.getElementById("panel15").style.padding = "0px";
        document.getElementById("panel16").style.width = "0px";
        document.getElementById("panel16").style.padding = "0px";
        document.getElementById("panel17").style.width = "0px";
        document.getElementById("panel17").style.padding = "0px";
        document.getElementById("panel18").style.width = "0px";
        document.getElementById("panel18").style.padding = "0px";
        document.getElementById("panel19").style.width = "0px";
        document.getElementById("panel19").style.padding = "0px";
        document.getElementById("panel20").style.width = "1281px";
        document.getElementById("panel20").style.padding = "50px";
    }
    document.getElementById("panel11").style.transitionDuration = "300ms";
    document.getElementById("panel12").style.transitionDuration = "300ms";
    document.getElementById("panel13").style.transitionDuration = "300ms";
    document.getElementById("panel14").style.transitionDuration = "300ms";
    document.getElementById("panel15").style.transitionDuration = "300ms";
    document.getElementById("panel16").style.transitionDuration = "300ms";
    document.getElementById("panel17").style.transitionDuration = "300ms";
    document.getElementById("panel18").style.transitionDuration = "300ms";
    document.getElementById("panel19").style.transitionDuration = "300ms";
    document.getElementById("panel20").style.transitionDuration = "300ms";
}

function gob1(){
    checker2 = (checker2-1+10)%10;
    if(checker2 == 0){
        document.getElementById("panel11").style.width = "1281px";
        document.getElementById("panel11").style.padding = "50px";
        document.getElementById("panel12").style.width = "0px";
        document.getElementById("panel12").style.padding = "0px";
        document.getElementById("panel13").style.width = "0px";
        document.getElementById("panel13").style.padding = "0px";
        document.getElementById("panel14").style.width = "0px";
        document.getElementById("panel14").style.padding = "0px";
        document.getElementById("panel15").style.width = "0px";
        document.getElementById("panel15").style.padding = "0px";
        document.getElementById("panel16").style.width = "0px";
        document.getElementById("panel16").style.padding = "0px";
        document.getElementById("panel17").style.width = "0px";
        document.getElementById("panel17").style.padding = "0px";
        document.getElementById("panel18").style.width = "0px";
        document.getElementById("panel18").style.padding = "0px";
        document.getElementById("panel19").style.width = "0px";
        document.getElementById("panel19").style.padding = "0px";
        document.getElementById("panel20").style.width = "0px";
        document.getElementById("panel20").style.padding = "0px";
    }
    else if(checker2 == 1){
        document.getElementById("panel11").style.width = "0px";
        document.getElementById("panel11").style.padding = "0px";
        document.getElementById("panel12").style.width = "1281px";
        document.getElementById("panel12").style.padding = "50px";
        document.getElementById("panel13").style.width = "0px";
        document.getElementById("panel13").style.padding = "0px";
        document.getElementById("panel14").style.width = "0px";
        document.getElementById("panel14").style.padding = "0px";
        document.getElementById("panel15").style.width = "0px";
        document.getElementById("panel15").style.padding = "0px";
        document.getElementById("panel16").style.width = "0px";
        document.getElementById("panel16").style.padding = "0px";
        document.getElementById("panel17").style.width = "0px";
        document.getElementById("panel17").style.padding = "0px";
        document.getElementById("panel18").style.width = "0px";
        document.getElementById("panel18").style.padding = "0px";
        document.getElementById("panel19").style.width = "0px";
        document.getElementById("panel19").style.padding = "0px";
        document.getElementById("panel20").style.width = "0px";
        document.getElementById("panel20").style.padding = "0px";
    }
    else if(checker2 == 2){
        document.getElementById("panel11").style.width = "0px";
        document.getElementById("panel11").style.padding = "0px";
        document.getElementById("panel12").style.width = "0px";
        document.getElementById("panel12").style.padding = "0px";
        document.getElementById("panel13").style.width = "1281px";
        document.getElementById("panel13").style.padding = "50px";
        document.getElementById("panel14").style.width = "0px";
        document.getElementById("panel14").style.padding = "0px";
        document.getElementById("panel15").style.width = "0px";
        document.getElementById("panel15").style.padding = "0px";
        document.getElementById("panel16").style.width = "0px";
        document.getElementById("panel16").style.padding = "0px";
        document.getElementById("panel17").style.width = "0px";
        document.getElementById("panel17").style.padding = "0px";
        document.getElementById("panel18").style.width = "0px";
        document.getElementById("panel18").style.padding = "0px";
        document.getElementById("panel19").style.width = "0px";
        document.getElementById("panel19").style.padding = "0px";
        document.getElementById("panel10").style.width = "0px";
        document.getElementById("panel10").style.padding = "0px";
    }
    else if(checker2 == 3){
        document.getElementById("panel11").style.width = "0px";
        document.getElementById("panel11").style.padding = "0px";
        document.getElementById("panel12").style.width = "0px";
        document.getElementById("panel12").style.padding = "0px";
        document.getElementById("panel13").style.width = "0px";
        document.getElementById("panel13").style.padding = "0px";
        document.getElementById("panel14").style.width = "1281px";
        document.getElementById("panel14").style.padding = "50px";
        document.getElementById("panel15").style.width = "0px";
        document.getElementById("panel15").style.padding = "0px";
        document.getElementById("panel16").style.width = "0px";
        document.getElementById("panel16").style.padding = "0px";
        document.getElementById("panel17").style.width = "0px";
        document.getElementById("panel17").style.padding = "0px";
        document.getElementById("panel18").style.width = "0px";
        document.getElementById("panel18").style.padding = "0px";
        document.getElementById("panel19").style.width = "0px";
        document.getElementById("panel19").style.padding = "0px";
        document.getElementById("panel20").style.width = "0px";
        document.getElementById("panel20").style.padding = "0px";
    }
    else if(checker2 == 4){
        document.getElementById("panel11").style.width = "0px";
        document.getElementById("panel11").style.padding = "0px";
        document.getElementById("panel12").style.width = "0px";
        document.getElementById("panel12").style.padding = "0px";
        document.getElementById("panel13").style.width = "0px";
        document.getElementById("panel13").style.padding = "0px";
        document.getElementById("panel14").style.width = "0px";
        document.getElementById("panel14").style.padding = "0px";
        document.getElementById("panel15").style.width = "1281px";
        document.getElementById("panel15").style.padding = "50px";
        document.getElementById("panel16").style.width = "0px";
        document.getElementById("panel16").style.padding = "0px";
        document.getElementById("panel17").style.width = "0px";
        document.getElementById("panel17").style.padding = "0px";
        document.getElementById("panel18").style.width = "0px";
        document.getElementById("panel18").style.padding = "0px";
        document.getElementById("panel19").style.width = "0px";
        document.getElementById("panel19").style.padding = "0px";
        document.getElementById("panel20").style.width = "0px";
        document.getElementById("panel20").style.padding = "0px";
    }
    else if(checker2 == 5){
        document.getElementById("panel11").style.width = "0px";
        document.getElementById("panel11").style.padding = "0px";
        document.getElementById("panel12").style.width = "0px";
        document.getElementById("panel12").style.padding = "0px";
        document.getElementById("panel13").style.width = "0px";
        document.getElementById("panel13").style.padding = "0px";
        document.getElementById("panel14").style.width = "0px";
        document.getElementById("panel14").style.padding = "0px";
        document.getElementById("panel15").style.width = "0px";
        document.getElementById("panel15").style.padding = "0px";
        document.getElementById("panel16").style.width = "1281px";
        document.getElementById("panel16").style.padding = "50px";
        document.getElementById("panel17").style.width = "0px";
        document.getElementById("panel17").style.padding = "0px";
        document.getElementById("panel18").style.width = "0px";
        document.getElementById("panel18").style.padding = "0px";
        document.getElementById("panel19").style.width = "0px";
        document.getElementById("panel19").style.padding = "0px";
        document.getElementById("panel20").style.width = "0px";
        document.getElementById("panel20").style.padding = "0px";
    }
    else if(checker2 == 6){
        document.getElementById("panel11").style.width = "0px";
        document.getElementById("panel11").style.padding = "0px";
        document.getElementById("panel12").style.width = "0px";
        document.getElementById("panel12").style.padding = "0px";
        document.getElementById("panel13").style.width = "0px";
        document.getElementById("panel13").style.padding = "0px";
        document.getElementById("panel14").style.width = "0px";
        document.getElementById("panel14").style.padding = "0px";
        document.getElementById("panel15").style.width = "0px";
        document.getElementById("panel15").style.padding = "0px";
        document.getElementById("panel16").style.width = "0px";
        document.getElementById("panel16").style.padding = "0px";
        document.getElementById("panel17").style.width = "1281px";
        document.getElementById("panel17").style.padding = "50px";
        document.getElementById("panel18").style.width = "0px";
        document.getElementById("panel18").style.padding = "0px";
        document.getElementById("panel19").style.width = "0px";
        document.getElementById("panel19").style.padding = "0px";
        document.getElementById("panel20").style.width = "0px";
        document.getElementById("panel20").style.padding = "0px";
    }
    else if(checker2 == 7){
        document.getElementById("panel11").style.width = "0px";
        document.getElementById("panel11").style.padding = "0px";
        document.getElementById("panel12").style.width = "0px";
        document.getElementById("panel12").style.padding = "0px";
        document.getElementById("panel13").style.width = "0px";
        document.getElementById("panel13").style.padding = "0px";
        document.getElementById("panel14").style.width = "0px";
        document.getElementById("panel14").style.padding = "0px";
        document.getElementById("panel15").style.width = "0px";
        document.getElementById("panel15").style.padding = "0px";
        document.getElementById("panel16").style.width = "0px";
        document.getElementById("panel16").style.padding = "0px";
        document.getElementById("panel17").style.width = "0px";
        document.getElementById("panel17").style.padding = "0px";
        document.getElementById("panel18").style.width = "1281px";
        document.getElementById("panel18").style.padding = "50px";
        document.getElementById("panel19").style.width = "0px";
        document.getElementById("panel19").style.padding = "0px";
        document.getElementById("panel20").style.width = "0px";
        document.getElementById("panel20").style.padding = "0px";
    }
    else if(checker2 == 8){
        document.getElementById("panel11").style.width = "0px";
        document.getElementById("panel11").style.padding = "0px";
        document.getElementById("panel12").style.width = "0px";
        document.getElementById("panel12").style.padding = "0px";
        document.getElementById("panel13").style.width = "0px";
        document.getElementById("panel13").style.padding = "0px";
        document.getElementById("panel14").style.width = "0px";
        document.getElementById("panel14").style.padding = "0px";
        document.getElementById("panel15").style.width = "0px";
        document.getElementById("panel15").style.padding = "0px";
        document.getElementById("panel16").style.width = "0px";
        document.getElementById("panel16").style.padding = "0px";
        document.getElementById("panel17").style.width = "0px";
        document.getElementById("panel17").style.padding = "0px";
        document.getElementById("panel18").style.width = "0px";
        document.getElementById("panel18").style.padding = "0px";
        document.getElementById("panel19").style.width = "1281px";
        document.getElementById("panel19").style.padding = "50px";
        document.getElementById("panel20").style.width = "0px";
        document.getElementById("panel20").style.padding = "0px";
    }
    else if(checker2 == 9){
        document.getElementById("panel11").style.width = "0px";
        document.getElementById("panel11").style.padding = "0px";
        document.getElementById("panel12").style.width = "0px";
        document.getElementById("panel12").style.padding = "0px";
        document.getElementById("panel13").style.width = "0px";
        document.getElementById("panel13").style.padding = "0px";
        document.getElementById("panel14").style.width = "0px";
        document.getElementById("panel14").style.padding = "0px";
        document.getElementById("panel15").style.width = "0px";
        document.getElementById("panel15").style.padding = "0px";
        document.getElementById("panel16").style.width = "0px";
        document.getElementById("panel16").style.padding = "0px";
        document.getElementById("panel17").style.width = "0px";
        document.getElementById("panel17").style.padding = "0px";
        document.getElementById("panel18").style.width = "0px";
        document.getElementById("panel18").style.padding = "0px";
        document.getElementById("panel19").style.width = "0px";
        document.getElementById("panel19").style.padding = "0px";
        document.getElementById("panel20").style.width = "1281px";
        document.getElementById("panel20").style.padding = "50px";
    }
    document.getElementById("panel11").style.transitionDuration = "300ms";
    document.getElementById("panel12").style.transitionDuration = "300ms";
    document.getElementById("panel13").style.transitionDuration = "300ms";
    document.getElementById("panel14").style.transitionDuration = "300ms";
    document.getElementById("panel15").style.transitionDuration = "300ms";
    document.getElementById("panel16").style.transitionDuration = "300ms";
    document.getElementById("panel17").style.transitionDuration = "300ms";
    document.getElementById("panel18").style.transitionDuration = "300ms";
    document.getElementById("panel19").style.transitionDuration = "300ms";
    document.getElementById("panel20").style.transitionDuration = "300ms";
}
