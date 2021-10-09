import { useState, useEffect } from 'react';

function App() {
    const [time, setTime] = useState(new Date().toLocaleTimeString());

    useEffect(() => {
        console.log('useEffect');
        const interval = setInterval(() => {
            setTime(new Date().toLocaleTimeString());
        }, 1000);
        
        return () => {
            clearInterval(interval);
        };
    }, []);

    useEffect(() => {
        console.log(time);
    }, [time]);

    return (
        <>
            <p>{time}</p>
        </>
    );
}

export default App;