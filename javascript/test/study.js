require("should");

//https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference
describe("functional programming", function(){
 	it("map an array of numbers", function(){
		var numbers = [1, 2, 3, 4];
		var doubles = numbers.map(function(i){
			return i*2;
		});

		doubles.should.be.eql([2, 4, 6, 8]);
 	});

 	it("use map reverse a string", function(){
 		var str='12345';
 		var r = [].map.call(str, function(x){
 			return x;
 		}).reverse().join('');

 		r.should.be.eql('54321');
 	});

 	it("filter out small values", function(){
 		var filtered = [1,2,3,4,5].filter(function(x){
 			return x > 3;
 		});

 		filtered.should.be.eql([4,5]);
 	});

 	it("sum up all values within an array", function(){
 		var total = [1,2,3,4].reduce(function(a, b){
 			return a+b;
 		}, 3); //3 is a initial value

 		total.should.be.eql(13);
 	});

 	it("return a portion of an existing array", function(){
 		var fruits = ['Banana','Orange','Lemon','Apple','Mango'].slice(1, 3) // [1, 3)

 		fruits.should.be.eql(['Orange', 'Lemon']);
 	});

 	it("insert a element at index 2", function(){
 		var myFish = ['angel', 'clown', 'mandarin', 'surgeon'];
 		var removed = myFish.splice(2, 0, 'drum');

 		myFish.should.be.eql(['angel', 'clown', 'drum','mandarin', 'surgeon']);
 		removed.should.be.eql([]);
 	});

 	it("remove a element at index 3", function(){
 		var myFish = ['angel', 'clown', 'mandarin', 'surgeon'];
 		var removed = myFish.splice(3, 1);

 		myFish.should.be.eql(['angel', 'clown', 'mandarin']);
 		removed.should.be.eql(['surgeon']);
 	});

 	it("insert 1 element from index 2 and insert an element", function(){
 		var myFish = ['angel', 'clown', 'mandarin', 'surgeon'];
 		var removed = myFish.splice(2, 1, "trumpet");

 		myFish.should.be.eql(['angel', 'clown', 'trumpet', 'surgeon']);
 		removed.should.be.eql(['mandarin']);
 	});
});