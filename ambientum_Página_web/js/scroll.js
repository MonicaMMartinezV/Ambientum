$(document).ready(function(){
    let nav = document.querySelector('.opuesto');   
    let links=document.querySelectorAll('.nav__links'); 
    let ancho = window.innerWidth;    
    let scrollTo=window.scrollY;  
    //verificar el estado de la barra del menú dependiendo del ancho de la ventana
    if(ancho<=800){
        nav.classList.remove('opuesto');
        nav.classList.add('nav_container');
        for (var i = 0; i<links.length; i++) {
            links[i].classList.add("nav__links_opuesto");
            links[i].classList.remove("nav__links");
        }
    }
    else if(scrollTo>0){
        nav.classList.add('opuesto');
        nav.classList.remove('nav_container');
        for (var i = 0; i<links.length; i++) {
            links[i].classList.remove("nav__links_opuesto");
            links[i].classList.add("nav__links");
        }
    }

    window.addEventListener('scroll',()=>{
        scrollTo=window.scrollY;  
        if(scrollTo>0){
            
            if(ancho>800){
                nav.classList.add('nav_container');
                nav.classList.remove('opuesto');
                for (var i = 0; i<links.length; i++) {
                    links[i].classList.remove("nav__links");
                    links[i].classList.add("nav__links_opuesto");
                }
            }
        }
        else{
            if(ancho>800){
                nav.classList.add('opuesto');
                nav.classList.remove('nav_container');
                for (var i = 0; i<links.length; i++) {
                    links[i].classList.remove("nav__links_opuesto");
                    links[i].classList.add("nav__links");
                }
            }
        }
        
    });

    window.addEventListener('resize',()=>{
        scrollTo=window.scrollY;  
        ancho = window.innerWidth;
        if(ancho<=800){
            nav.classList.remove('opuesto');
            nav.classList.add('nav_container');
            for (var i = 0; i<links.length; i++) {
                links[i].classList.add("nav__links_opuesto");
                links[i].classList.remove("nav__links");
            }
        }
        else if(scrollTo==0){
            nav.classList.add('opuesto');
            nav.classList.remove('nav_container');
            for (var i = 0; i<links.length; i++) {
                links[i].classList.remove("nav__links_opuesto");
                links[i].classList.add("nav__links");
            }
        }

    });

});
