import React from 'react';
import ReactDOM from 'react-dom';

import App from './App';

const appElement = <React.StrictMode><App /></React.StrictMode>;

ReactDOM.render(
    appElement,
    document.getElementById('root')
);