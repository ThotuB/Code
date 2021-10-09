import { useState } from 'react';

function App() {
    const [count1, setCount1] = useState(0);
    const [count2, setCount2] = useState(5);

    return (
        <>
            <button onClick={() => setCount1(count1 + 1)}>
                {count1}
            </button>

            <button onClick={() => setCount2(count2 + 1)}>
                {count2}
            </button>
            
            <button onClick={() => {
                setCount1(count1 + 1);
                setCount2(count2 + 1);
            }}>
                {count1 + count2}
            </button>
        </>
    );
}

export default App;