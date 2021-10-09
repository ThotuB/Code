import {Component} from 'react';

class Timer extends Component {
    constructor(props) {
        super(props);

        this.state = {
            secondsElapsed: 0
        };
    }

    //* METHODS
    tick() {
        this.setState({
            secondsElapsed: this.state.secondsElapsed + 1
        });
    }

    //* OVERRIDES
    componentDidMount() {
        this.interval = setInterval(() => this.tick(), 1000);
    }

    componentWillUnmount() {
        clearInterval(this.interval);
    }

    render() {
        return (
            <div>Timer: {this.state.secondsElapsed} secs</div>
        );
    }
}

export default Timer;