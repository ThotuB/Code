import { useContext, createContext } from "react";

const themes = {
    light: {
        text: "LIGHT",
        foreground: "#000000",
        background: "#eeeeee"
    },
    dark: {
        text: "DARK",
        foreground: "#ffffff",
        background: "#222222"
    }
};

const ThemeContext = createContext(themes.light);

function App() {
    return (
        <ThemeContext.Provider value={themes.dark}>
            <Toolbar />
        </ThemeContext.Provider>
    );
}

function Toolbar(props) {
    return (
        <>
            <ThemedButton />
        </>
    );
}

function ThemedButton() {
    const theme = useContext(ThemeContext);
    return (
        <button style={{ background: theme.background, color: theme.foreground }}>
            {theme.text} THEME!
        </button>
    );
}

export default App;