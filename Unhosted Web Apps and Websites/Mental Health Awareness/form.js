function calculateStress() {
    const happiness = document.getElementById('happiness').value;
    const sadness = document.getElementById('sadness').value;
    const anxiety = document.getElementById('anxiety').value;
    const pressure = document.getElementById('pressure').value;
  
    let stress = 0;
  
    if (sadness >= 7 && anxiety >= 7) {
      stress = 10;
    } else if (happiness >= 7) {
      stress = 2;
    } else {
      stress = Math.floor((sadness + anxiety) / 2);
    }
  
    if (pressure === 'yes') {
      stress += 3;
    }
  
    document.getElementById('stress-level-value').innerHTML = stress;
    document.getElementById('stress-level').style.display = 'block';
  }

