import React, { useState } from 'react';

function Slides({slides}) {
    const [index, setIndex] = useState(0)

    const currentSlide = slides[index];
    console.log(slides.length)

    return (
        <div>
            <div id="navigation" className="text-center">
                <button data-testid="button-restart" className="small outlined"
                  onClick={() => setIndex(0)}
                  disabled={index === 0}
                >
                    Restart
                </button>
                <button data-testid="button-prev" className="small"
                  onClick={() => setIndex(index - 1)}
                  disabled={index === 0}
                >
                    Prev
                </button>
                <button data-testid="button-next" className="small"
                  onClick={() => setIndex(index + 1)}
                  disabled={index === slides.length - 1}
                >
                    Next
                </button>
            </div>
            <div id="slide" className="card text-center">
                <h1 data-testid="title">{currentSlide.title}</h1>
                <p data-testid="text">{currentSlide.text}</p>
            </div>
        </div>
    );

}

export default Slides;
