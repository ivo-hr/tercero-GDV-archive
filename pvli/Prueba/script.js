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

}

function carameldansen(){
  let clas1 = document.getElementsByClassName('chachi');
  let clas2 = document.getElementsByClassName('chachi2');
  for (i = 0; i < clas1.length; i++){
    clas1[i].className = 'chachi2';
    //clas1[i].style = name2;
  }
  for (i = 0; i < clas2.length; i++){
    clas2[i].className = 'chachi';
  }


}
  
  // if (clas.style.visibility=='hidden'){
  //   clas.style.visibility='visible';
  // }
  // else
  // clas.style.visibility='hidden';
