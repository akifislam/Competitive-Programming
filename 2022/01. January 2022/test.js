//Making Object in Javascript
// Object is like C++ Maps
var ourCat = {
  name: "worm",
  leg: 2,
  nose: 1,
  tab: 1,
  friends: ["everything!"],
};

console.log(ourCat["name"]);

console.log(ourCat);
ourCat.name = "Yen";
console.log(ourCat);
delete ourCat.tab;
console.log(ourCat);
ourCat["dress"] = "sweater";
console.log(ourCat);
