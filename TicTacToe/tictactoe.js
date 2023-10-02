window.addEventListener('DOMContentLoaded',() => {
    const tiles = Array.from(document.querySelectorAll(".one"));
    const playerDisplay = document.querySelector(".display-player");
    const resetButton = document.querySelector("#reset");
    const show = document.querySelector(".display");
    const ai = document.querySelector("#ai");
    const announcer = document.querySelector(".announcer");


    let board = ['','','','','','','','',''];
    let currentPlayer= "X";
    let isActive = true;
    var originBoard = Array.from(Array(9).keys());
    var AiPlayer = "O";
    var huPlayer = "X";
    //console.log(originBoard)

    const Xwon  = "Xwon";
    const Owon = "Owon";
    const Tie = "Tie";
    var isAi = false;
    ai.addEventListener("click",()=>isAi = true);
    const WinningConditions = [
        [0,1,2],
        [3,4,5],
        [6,7,8],
        [0,3,6],
        [1,4,7],
        [2,5,8],
        [0,4,8],
        [2,4,6]
    ];

    const announce = (type) => {
        switch(type){
            case "PLAYERO_WON":
                announcer.innerHTML='Player<span class="playerO">O</span> Won';
                break;
            case "PLAYERX_WON":
                announcer.innerHTML='Player<span class="playerX">X</span> Won';
                break;
            case "Tie":
                announcer.innerHTML ='Tie';        
        }
        announcer.classList.remove('hide');

    }

    const handleResultValidation =() => {
        let won = false;
        for(let i = 0; i <= 7; i++){
            let singleCondition = WinningConditions[i];
            let a = board[singleCondition[0]];
            let b = board[singleCondition[1]];
            let c = board[singleCondition[2]];

            if(a =='' || b == '' || c ==''){
                continue;
            }
            if(a == b && b == c){
                won  = true;
                break;
            }
        }
        if(won){
            announce(currentPlayer == "X" ? "PLAYERX_WON":"PLAYERO_WON");
            isActive = false;
            show.classList.add('show')
            return currentPlayer == "X" ? "PLAYERX_WON":"PLAYERO_WON";
        }
        if(!board.includes('')){
            announce("Tie");
            return 0;
        }
    }
    const updateBoard = (index) => {
        originBoard[index] = currentPlayer;//console.log(originBoard)
        board[index] = currentPlayer;
    } 

    const changePlayer =() => {
        playerDisplay.classList.remove(`player${currentPlayer}`);
        currentPlayer = currentPlayer =="X" ? "O" :"X";
        playerDisplay.innerText = currentPlayer;
        playerDisplay.classList.add(`player${currentPlayer}`);
    }
    const userAction =(tile,index,ai) => {
        if(isValidation(tile) && isActive){
            tile.innerText = currentPlayer;
            tile.classList.add(`player${currentPlayer}`);
            updateBoard(index);
            handleResultValidation();
             changePlayer();
        }
    }
    const turn =(tile,index,ai) => {
        console.log(ai)
        if(typeof(originBoard[index]) == "number"){
        userAction(tile,index);
        userAction(tiles[bestSpot(originBoard,AiPlayer)],bestSpot(originBoard,AiPlayer));
        }
    }

    const isValidation = (tile) => {
        if(tile.innerText === "X" || tile.innerText === "O"){
            return false;
        }
        return true;
    }

    tiles.forEach((tile,index) => {
        tile.addEventListener("click",()=> turn(tile,index,true));
    });

const resetBoard =() => {
    board = ['','','','','','','','',''];
    tiles.forEach((tile) => {
        tile.innerText = board[0];
    })
    isActive = true;
    isAi = false;
    originBoard = Array.from(Array(9).keys());
    announcer.classList.add('hide');
    show.classList.remove('show');
    playerDisplay.innerText = "X";
    currentPlayer = "X";
}

//console.log(board)
    
    resetButton.addEventListener('click',resetBoard);


const checkWin =(board,player) => {
    let plays = board.reduce((a,e,i) => (e === player) ? a.concat(i):a,[]);
    let gameWon = null;
    for(let [index,win] of WinningConditions.entries()){
        if(win.every(elem =>plays.indexOf(elem) > -1)){
            gameWon = {index:index,player:player};
            break;
        }
    }
    return gameWon;
}

const emptySquares = (originBoard) => {
    let temp = [];
   console.log(originBoard)
    temp= originBoard.filter((s) => typeof(s) =='number');
   // console.log(temp)
    return temp;
}
const bestSpot = (originBoard,player) => {
   return minMax(originBoard,AiPlayer).index;
}
const checkTie =() => {
    if(emptySquares().length == 0){
        return true;
    }
    else{
        return false;
    }
}

const minMax =(board,player) => {
    let availSpots = emptySquares(board);
    console.log("runnin")
    if(checkWin(board,player)){
        return {score:-10}
    }
    else if(checkWin(board,AiPlayer)){
        return {score:10};
    }
    else if(availSpots.length == 0){
        return {score:0};
    }

    var moves = [];
    for(var i = 0; i < availSpots.length;i++){
        var move = {};
        move.index = board[availSpots[i]];
        board[availSpots[i]] = player;

        if(player == AiPlayer){
            var result = minMax(board,huPlayer);
            move.score = result.score;
        }
        else{
            var result = minMax(board,AiPlayer);
            move.score = result.score; 
        }
        board[availSpots[i]] = move.index;
        moves.push(move)
    }
    var bestMove;
    if(player == AiPlayer){
        var bestScore = -Infinity;
        for(let i = 0; i < moves.length;i++){
            if(moves[i].score > bestScore){
                bestScore = moves[i].score;
                bestMove = i;
            }
        }
    }else{
        var bestScore = Infinity;
        for(let i = 0; i < moves.length; i++){
            if(moves[i].score < bestScore){
                bestScore = moves[i].score;
                bestMove = i;
            }
        }
    }
    return moves[bestMove];
}
});