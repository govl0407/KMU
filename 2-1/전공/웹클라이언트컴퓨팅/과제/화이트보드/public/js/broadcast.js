window.addEventListener('load', function(){
    // 변수를 선언합니다.
    let color = 'black';
    let width = 1;
    let isDown = false;
    let newPoint, oldPoint;
    let clear = false;
    // 소켓을 연결합니다.
    const socket = io.connect();

    // 캔버스를 추출합니다.
    const canvas = document.querySelector('#canvas');
    const pen = document.querySelector('#pen');
    const eraser = document.querySelector('#eraser');
    const wid = document.querySelector('#wid');
    const context = canvas.getContext('2d');
    const pen_col = document.querySelector('#pen_color');
    const board_clear = document.querySelector('#board_clear');

    // 마우스 이벤트를 연결합니다.
    canvas.addEventListener('mousedown', function (event) {
        isDown = true;
        const rect = canvas.getBoundingClientRect();
        oldPoint = {
            x: event.clientX - rect.left,
            y: event.clientY - rect.top
        };
    });

    canvas.addEventListener('mousemove', function(event) {
        if (!isDown) { return; }
        const rect = canvas.getBoundingClientRect();
        newPoint = {
            x: event.clientX - rect.left,
            y: event.clientY - rect.top
        };
        socket.emit('line', {
            x1: oldPoint.x,
            y1: oldPoint.y,
            x2: newPoint.x,
            y2: newPoint.y,
            color: pen_col.value,
            width: width
        });
        
        oldPoint = newPoint;
    });

    canvas.addEventListener('mouseup', function(event) {
        isDown = false;
        const rect = canvas.getBoundingClientRect();
        oldPoint = {
            x: event.clientX - rect.left,
            y: event.clientY - rect.top
        };
    });

    // 입력 양식 이벤트를 연결합니다.
    pen.addEventListener('click', function(event) {
        width = 1;
        color = pen_col.value;
        wid.value=width;
    });

    eraser.addEventListener('click', function(event) {
        width = 10;
        pen_col.value = 'white';
        wid.value=width;
    });

    board_clear.addEventListener('click', function(event) {//보드리셋 
        socket.emit('line', {
            x1: 0,
            y1: 0,
            x2: 100000,
            y2: 100000000000,
            color: 'white',
            width: 1000000
        });
    });

    wid.addEventListener('change', function(event) {
        width=wid.value;
    });

    // 소켓 이벤트를 연결합니다.
    socket.on('line', function (data) {
        console.log(data);
        console.log(canvas.getBoundingClientRect());
        context.beginPath();
        context.lineWidth = data.width;
        context.strokeStyle = data.color;
        context.moveTo(data.x1, data.y1);
        context.lineTo(data.x2, data.y2);
        context.stroke();
    });

    //chat
    const chatarea = document.querySelector('#chatarea');
    const nickname = document.querySelector('#nickname');
    const chat = document.querySelector('#chat');
    const submit = document.querySelector('#submit');
    const chatwindow = document.querySelector('#chatarea');
    
    submit.addEventListener('click', function(event) {//chat
        let chat_log ="(" + nickname.value+")" + chat.value + "\n"; 
    
        socket.emit('chat', {
            chaat : chat_log
        });
    });


    socket.on('chat',function (datam, cnt){
        console.log(datam);
        chatwindow.value += "[#"+ cnt +"] "
        chatwindow.value += datam.chaat;
    });
});
