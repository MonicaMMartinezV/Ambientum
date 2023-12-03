$(document).ready(main);/*se ejecuta el codigo hasta que ttodo el doc haya cargado*/ 

var cont = 1;

function main(){
    $('.bt-menu').click(function(){
        
        if(cont==1){
            $('nav').animate({
                left: '0'
            });
            cont = 0;
        }
        else{
            cont=1;
            $('nav').animate({
                left: '-100%'
            });
        }

    });
};

window.addEventListener("scroll",function(){
    var bar_menu=document.querySelector(".menu_bar");
    bar_menu.classList.toggle("sticky",window.scrollY>0 && cont==1);

});