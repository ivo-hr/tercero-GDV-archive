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

function carameldansen(name){
  let clas = document.getElementsByClassName(name);

  const colour = Math.floor(Math.random() * 10000000).toString(16);

  for(i = 0; i < clas.length; i++)
    clas[i].style.color = ("#" + colour);
}

function  caramelAll(){
  carameldansen('barf');
  carameldansen('chachi');
}
