function button1In(){
    document.getElementById("butt").style.backgroundColor = "white";
    document.getElementById("butt").style.borderColor = "black";
    document.getElementById("p2").style.color = "black";
    document.getElementById("butt").style.transitionDuration = "0.5s";
    document.getElementById("p2").style.transitionDuration = "0.5s";
}

function button1Out(){
    document.getElementById("butt").style.backgroundColor = "transparent";
    document.getElementById("butt").style.borderColor = "white";
    document.getElementById("p2").style.color = "white";
    document.getElementById("butt").style.transitionDuration = "0.5s";
    document.getElementById("p2").style.transitionDuration = "0.5s";
}

function cont(x){
    document.getElementById(x).scrollIntoView();
}

function button2In(){
    document.getElementById("btn2").style.scale = "1.5";
}

function button2Out(){
    document.getElementById("btn2").style.scale = "1";
}