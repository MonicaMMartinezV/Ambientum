$(document).ready(function(){
    var height = $(window).height();
    $('.sombra').height(height);

    var boton = document.querySelector('.location');
    let mapa = document.querySelector('.mapa');
    let caja=document.querySelector('.sombra');
    let seccion=document.querySelector('.hero__container');
    let menu=document.querySelector('.nav__link--menu');
    let boton_menu=document.querySelector('.nav__menu');

    console.log(menu);
    console.log(boton);
    console.log(caja);
    //boton para desplegar el mapa
    boton.addEventListener("click",() => {
        mapa.classList.toggle('location-hiden');
        setTimeout(function(){
            mapa.style.transform= 'translate(900px)';
            seccion.classList.toggle('hero__sombra');
            caja.classList.toggle('animado');
        },100);
        
    });

   caja.addEventListener("click",() => {
        caja.classList.toggle('animado');
        mapa.style.transform= 'translate(-852px)';
        caja.classList.toggle('no_animado');
        setTimeout(function(){
            caja.classList.toggle('no_animado');
        },1100);
        seccion.classList.toggle('hero__sombra');
        setTimeout(function(){
            mapa.classList.toggle('location-hiden');
        },800);
    });

    let cont=0;

    boton_menu.addEventListener("click",()=>{
        if(cont==2){
            menu.style.transform= 'translate(-290px)';
            cont=1;
        }else{
            menu.style.transform= 'translate(290px)';
            cont=2;
        }
        
    });

    window.onresize = function(){

        anchoVentana = window.innerWidth;
        if(anchoVentana > 800 && cont==1){
            menu.style.transform= 'translate(0px)';
        }else if(anchoVentana > 800 && cont==2){
            menu.style.transform= 'translate(0px)';
        }
        console.log(anchoVentana);
       
    };

   
}
);

