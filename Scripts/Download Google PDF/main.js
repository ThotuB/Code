let jspdf = document.createElement( "script" );

jspdf.onload = function () {
    let pdf = new jsPDF({
        orientation: "landscape",
        unit: "px",
        format: [788, 420]
    });
    let elements = document.getElementsByTagName( "img" );

    for (let i = 0; i < elements.length; i++) {
        let img = elements[i];
        if (!/^blob:/.test(img.src)) {
            continue ;
        }
        let canvasElement = document.createElement( 'canvas' );
        canvasElement.width = img.width;
        canvasElement.height = img.height;
        canvasElement
            .getContext( "2d" )
            .drawImage(img, 0, 0, img.width, img.height);

        let imgData = canvasElement.toDataURL("image/jpeg" , 1.0);
        pdf.addImage(imgData, 'JPEG' , 0, 0);

        if (i < elements.length - 1) {
            pdf.addPage();
        }
    }
    pdf.save( "download.pdf" );
};

jspdf.src = 'https://cdnjs.cloudflare.com/ajax/libs/jspdf/1.3.2/jspdf.min.js' ;
document.body.appendChild(jspdf);
