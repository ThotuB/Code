let jspdf = document.createElement( "script" );
jspdf.src = 'https://cdnjs.cloudflare.com/ajax/libs/jspdf/1.3.2/jspdf.min.js' ;

jspdf.onload = function () {
    let pdf = new jsPDF();
    let elements = document.getElementsByTagName( "img" );

    // let index = 0;
    for (let img of elements) {
        if (!/^blob:/.test(img.src)) {
            continue ;
        }
        let canvasElement = document.createElement( 'canvas' );
        canvasElement.width = img.width;
        canvasElement.height = img.height;
        canvasElement
            .getContext( "2d" )
            .drawImage(img, 0, 0, img.width, img.height);

        var image = canvasElement.toDataURL("image/png").replace("image/png", "image/octet-stream");  // here is the most important part because if you dont replace you will get a DOM 18 exception.

        window.location.href = image; // it will save locally
            
//         let imgData = canvasElement.toDataURL("image/jpeg" , 1.0);
//         pdf.addImage(imgData, 'JPEG' , 0, 0);
// 
//         if (index < elements.length - 1) {
//             pdf.addPage();
//         }
//         index++;
    }
    pdf.save( "download.pdf" );
};

document.body.appendChild(jspdf);
