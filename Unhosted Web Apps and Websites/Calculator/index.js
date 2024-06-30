var temp = 0;
var val = 0;
var sign = "_";
document.getElementById("nV").innerHTML = val;

function tV(x){
    temp = (temp*10) + x;
    document.getElementById("tV").innerHTML = temp;
}

function si(x){
    if(x == "+"){
        if(sign == "+"){
            val = val + temp;
        }
        else if(sign == "-"){
            val = val - temp;
        }
        else if(sign == "x"){
            val = val * temp;
        }
        else if(sign == "/"){
            val = val / temp;
        }
        else if(sign == "_"){
            val = temp;
        }
        sign = x;
        temp = 0;
        document.getElementById("nV").innerHTML = val;
        document.getElementById("tV").innerHTML = temp;
    }
    else if(x == "-"){
        if(sign == "+"){
            val = val + temp;
        }
        else if(sign == "-"){
            val = val - temp;
        }
        else if(sign == "x"){
            val = val * temp;
        }
        else if(sign == "/"){
            val = val / temp;
        }
        else if(sign == "_"){
            val = temp;
        }
        sign = x;
        temp = 0;
        document.getElementById("nV").innerHTML = val;
        document.getElementById("tV").innerHTML = temp;
    }
    else if(x == "x"){
        if(sign == "+"){
            val = val + temp;
        }
        else if(sign == "-"){
            val = val - temp;
        }
        else if(sign == "x"){
            val = val * temp;
        }
        else if(sign == "/"){
            val = val / temp;
        }
        else if(sign == "_"){
            val = temp;
        }
        sign = x;
        temp = 0;
        document.getElementById("nV").innerHTML = val;
        document.getElementById("tV").innerHTML = temp;
    }
    else if(x == "/"){
        if(sign == "+"){
            val = val + temp;
        }
        else if(sign == "-"){
            val = val - temp;
        }
        else if(sign == "x"){
            val = val * temp;
        }
        else if(sign == "/"){
            val = val / temp;
        }
        else if(sign == "_"){
            val = temp;
        }
        sign = x;
        temp = 0;
        document.getElementById("nV").innerHTML = val;
        document.getElementById("tV").innerHTML = temp;
    }
}

function ot(x){
    if(x == "C"){
        temp = ~~(temp/10);
        document.getElementById("tV").innerHTML = temp;
    }
    else if(x == "AC"){
        temp = 0;
        val = 0;
        sign = "_";
        document.getElementById("tV").innerHTML = temp;
        document.getElementById("nV").innerHTML = val;
    }
}

function eq(){
    if(sign == "+"){
        val = val + temp;
    }
    else if(sign == "-"){
        val = val - temp;
    }
    else if(sign == "x"){
        val = val * temp;
    }
    else if(sign == "/"){
        val = val / temp;
    }
    else if(sign == "_"){
        val = temp;
    }
    temp = val;
    val = 0;
    document.getElementById("nV").innerHTML = val;
    document.getElementById("tV").innerHTML = temp;
}