// default values
let game = {
    title: 'Tetris'
}

let [title, platform = 'PC'] = game
console.log(`${title} on ${platform}`)
