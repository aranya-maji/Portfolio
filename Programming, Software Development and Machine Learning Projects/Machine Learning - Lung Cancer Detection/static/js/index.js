function hovin(x,y){
    document.getElementById(x).style.backgroundColor = '#AAD7DA';
    document.getElementById(x).style.transitionDuration = '300ms';
    document.getElementById(y).style.color = 'black';
    document.getElementById(y).style.transitionDuration = '300ms';
}

function hovout(x,y){
    document.getElementById(x).style.backgroundColor = 'transparent';
    document.getElementById(x).style.transitionDuration = '300ms';
    document.getElementById(y).style.color = 'white';
    document.getElementById(y).style.transitionDuration = '300ms';
}

function bannerin(x,y){
    document.getElementById(x).style.filter = 'blur(10px)';
    document.getElementById(x).style.transitionDuration = '300ms';
    document.getElementById(y).style.color = 'white';
    document.getElementById(y).style.transitionDuration = '300ms';
}

function bannerout(x,y){
    document.getElementById(x).style.filter = 'blur(0px)';
    document.getElementById(x).style.transitionDuration = '300ms';
    document.getElementById(y).style.color = 'transparent';
    document.getElementById(y).style.transitionDuration = '300ms';
}

function meter(x){
    var y = 45 + (1.8 * x);
    document.getElementById("bar").style.rotate = y + 'deg';
    document.getElementById("bar").style.transitionDuration = '1000ms';
    document.getElementById("acc").innerHTML = x + '%';
}

var counter = 0;
document.getElementById("container1").style.height = "400px";
document.getElementById("container2").style.height = "0px";
document.getElementById("container3").style.height = "0px";
document.getElementById("container4").style.height = "0px";
document.getElementById("container1").style.transitionDuration = "500ms";
document.getElementById("container2").style.transitionDuration = "500ms";
document.getElementById("container3").style.transitionDuration = "500ms";
document.getElementById("container4").style.transitionDuration = "500ms";

function goup(){
    counter = (counter + 4 + 1)%4;
    if(counter == 0)
    {
        document.getElementById("container1").style.height = "400px";
        document.getElementById("container2").style.height = "0px";
        document.getElementById("container3").style.height = "0px";
        document.getElementById("container4").style.height = "0px";
        document.getElementById("container1").style.transitionDuration = "500ms";
        document.getElementById("container2").style.transitionDuration = "500ms";
        document.getElementById("container3").style.transitionDuration = "500ms";
        document.getElementById("container4").style.transitionDuration = "500ms";
    }
    else if(counter == 1)
    {
        document.getElementById("container1").style.height = "0px";
        document.getElementById("container2").style.height = "400px";
        document.getElementById("container3").style.height = "0px";
        document.getElementById("container4").style.height = "0px";
        document.getElementById("container1").style.transitionDuration = "500ms";
        document.getElementById("container2").style.transitionDuration = "500ms";
        document.getElementById("container3").style.transitionDuration = "500ms";
        document.getElementById("container4").style.transitionDuration = "500ms";
    }
    else if(counter == 2)
    {
        document.getElementById("container1").style.height = "0px";
        document.getElementById("container2").style.height = "0px";
        document.getElementById("container3").style.height = "400px";
        document.getElementById("container4").style.height = "0px";
        document.getElementById("container1").style.transitionDuration = "500ms";
        document.getElementById("container2").style.transitionDuration = "500ms";
        document.getElementById("container3").style.transitionDuration = "500ms";
        document.getElementById("container4").style.transitionDuration = "500ms";
    }
    else if(counter == 3)
    {
        document.getElementById("container1").style.height = "0px";
        document.getElementById("container2").style.height = "0px";
        document.getElementById("container3").style.height = "0px";
        document.getElementById("container4").style.height = "400px";
        document.getElementById("container1").style.transitionDuration = "500ms";
        document.getElementById("container2").style.transitionDuration = "500ms";
        document.getElementById("container3").style.transitionDuration = "500ms";
        document.getElementById("container4").style.transitionDuration = "500ms";
    }
}

function godown(){
    counter = (counter + 4 - 1)%4;
    if(counter == 0)
    {
        document.getElementById("container1").style.height = "400px";
        document.getElementById("container2").style.height = "0px";
        document.getElementById("container3").style.height = "0px";
        document.getElementById("container4").style.height = "0px";
        document.getElementById("container1").style.transitionDuration = "500ms";
        document.getElementById("container2").style.transitionDuration = "500ms";
        document.getElementById("container3").style.transitionDuration = "500ms";
        document.getElementById("container4").style.transitionDuration = "500ms";
    }
    else if(counter == 1)
    {
        document.getElementById("container1").style.height = "0px";
        document.getElementById("container2").style.height = "400px";
        document.getElementById("container3").style.height = "0px";
        document.getElementById("container4").style.height = "0px";
        document.getElementById("container1").style.transitionDuration = "500ms";
        document.getElementById("container2").style.transitionDuration = "500ms";
        document.getElementById("container3").style.transitionDuration = "500ms";
        document.getElementById("container4").style.transitionDuration = "500ms";
    }
    else if(counter == 2)
    {
        document.getElementById("container1").style.height = "0px";
        document.getElementById("container2").style.height = "0px";
        document.getElementById("container3").style.height = "400px";
        document.getElementById("container4").style.height = "0px";
        document.getElementById("container1").style.transitionDuration = "500ms";
        document.getElementById("container2").style.transitionDuration = "500ms";
        document.getElementById("container3").style.transitionDuration = "500ms";
        document.getElementById("container4").style.transitionDuration = "500ms";
    }
    else if(counter == 3)
    {
        document.getElementById("container1").style.height = "0px";
        document.getElementById("container2").style.height = "0px";
        document.getElementById("container3").style.height = "0px";
        document.getElementById("container4").style.height = "400px";
        document.getElementById("container1").style.transitionDuration = "500ms";
        document.getElementById("container2").style.transitionDuration = "500ms";
        document.getElementById("container3").style.transitionDuration = "500ms";
        document.getElementById("container4").style.transitionDuration = "500ms";
    }
}

function scroller(x){
    document.getElementById(x).scrollIntoView();
}