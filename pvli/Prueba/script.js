function devuelveTextoDeAlerta() {
  return "uooooo! Vaya alerta";
}

function desaparece(nombre) {
	let clas = document.getElementsByClassName(nombre);

  for (i = 0; i < clas.length; i++){
    if (clas[i].style.visibility==='hidden'){
      clas[i].style.visibility='visible';
    }
    else
    clas[i].style.visibility='hidden';
  }

  };
  
  // if (clas.style.visibility=='hidden'){
  //   clas.style.visibility='visible';
  // }
  // else
  // clas.style.visibility='hidden';
