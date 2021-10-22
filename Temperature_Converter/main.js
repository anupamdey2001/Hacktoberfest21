const cel = document.getElementById("cel");
    const fah = document.getElementById("fah");
    const kel = document.getElementById("kel");

    cel.addEventListener('input',function(){
        let ctemp = parseFloat(cel.value);
        fah.value = ctemp * 9/5 + 32;
        kel.value = ctemp + 273.15;
    });
    
    fah.addEventListener('input',function(){
        let ftemp = parseFloat(fah.value);
        cel.value = (ftemp - 32) * 5/9;
        kel.value = (ftemp - 32) * 5/9 + 273.15;
    });

    kel.addEventListener('input',function(){
        let ktemp = parseFloat(kel.value);
        cel.value = ktemp - 273.15;
        fah.value = (ktemp - 273.15) * 9/5 + 32;
    });
    
