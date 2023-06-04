async function init() {
 var word = "고경희 웹";
 var query = encodeURI(word);
 let xhr = new XMLHttpRequest();
 xhr.open("GET", `http://localhost:8090/https://openapi.naver.com/v1/search/book.json?query=${query}&display=10&start=1`);   //프록시서버포트(8090)
 xhr.setRequestHeader("X-Requested-With", "XMLHttpRequest");
 xhr.setRequestHeader("X-Naver-Client-Id", "UHOdPmlUAieIdA58KgCR");
 xhr.setRequestHeader("X-Naver-Client-Secret", "BLbC99qsce");
 xhr.send();
 xhr.onreadystatechange = function () {
    if (xhr.readyState === 4 && xhr.status === 200) {
      let data = JSON.parse(xhr.responseText);
      console.log(data);
      const books = data.items.sort((a,b) => b.pubdate - a.pubdate);
      console.log(books);
      books.sort((a,b)=> a.pubdate - b.pubdate);
      display(books);
    }
 };
}

function display(books) {
  const result = document.querySelector('#result');
  let string = '';
  books.forEach((book) => {
    string += `<table><tr><th>제목</th><td>${book.title}</td></tr>
                <tr><th>저자</th><td>${book.author}</td></tr>
                <tr><th>발행일</th><td>${book.pubdate}</td></tr>
                <tr></tr>
              </table>`;
  });
  result.innerHTML = string;
}

init();
