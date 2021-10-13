import { Component } from "react";

class Button extends Component {
    constructor(props) {
        console.log("constructor");
        super(props);

        this.state = {
            counter: 0,
            color: {
                r: 0,
                g: 0,
                b: 0
            }
        };

        this.handleClick = this.handleClick.bind(this);
        this.changeColor = this.changeColor.bind(this);
    }

    // METHODS
    changeColor() {
        console.log("changeColor");
        this.setState({
            color: {
                r: Math.floor(Math.random() * 256),
                g: Math.floor(Math.random() * 256),
                b: Math.floor(Math.random() * 256)
            }
        });
    }

    handleClick() {
        console.log("handleClick");
        this.setState ({
            counter: this.state.counter + 1
        });
        if ( this.state.counter % 5 === 0 ) {
            this.changeColor();
        }
    }

    // OVERRIDES
    componentDidMount() {
        console.log("componentDidMount");
    }

    componentDidUpdate() {
        console.log("componentDidUpdate");
    }

    componentWillUnmount() {
        console.log("componentWillUnmount");
    }

    render() {
        console.log("render");

        let r = this.state.color.r;
        let g = this.state.color.g;
        let b = this.state.color.b;

        return (
            <button 
                style={{backgroundColor: `rgb(${r}, ${g}, ${b})`,
                        width: "100px",
                        height: "100px",
                        fontSize: "50px",
                        color: `rgb(${255-r}, ${255-g}, ${255-b})`
                    }}
                onClick={this.handleClick}
            >
                {this.state.counter}
            </button>
        );
    }
}

export default Button;