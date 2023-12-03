/*$(document).ready(function(){
    // El cursor entra en el menú
    $('.texto').mouseover(function(){
        $('.texto').addClass('despliega');
    });

});
      
*/
var boton = document.querySelector('.texto');
let boton2 = document.querySelector('.texto2');
console.log(boton);
boton.addEventListener("mouseleave",() => { 
    boton2.style.display='none';
});
boton.addEventListener("mouseenter",() => {
    boton2.style.display='inline-block';
});

/*boton.addEventListener("mouseenter",() => {
    boton.style.backgroundColor='blue';
});
**/
