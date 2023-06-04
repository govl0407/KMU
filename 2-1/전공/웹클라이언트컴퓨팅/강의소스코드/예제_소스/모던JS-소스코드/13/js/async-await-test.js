async function displayHello() {
  console.log("inside displayHello()");
}

displayHello();
console.log("after displayHello()");

async function whatsYourFavorite() {
  console.log("inside whatsYourFavorite()");
  let fav = "Javascript";
  return fav;   
}

async function displaySubject(subject) {
  console.log("inside displaySubject()");
  return `Hello, ${subject}`;      
}

async function init() {
  console.log("inside init1()");
  const fav = await whatsYourFavorite();
  console.log("inside init2()");
  const result = await displaySubject(fav);
  console.log("inside init3()");
  console.log(result);
}

init();
console.log("after init()");
