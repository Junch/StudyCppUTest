require("should");

describe("Happy Number", function(){
	var isHappy = function(n) {

		var s = [];
		var happy = function(n, s){
			if (s.indexOf(n) != -1){
				return false;
			}

			s.push(n);

			var digits = [];
			while(n > 0){
				digits.push(n%10);
				n = Math.floor(n/10);
			}

			var sum = 0;
			digits.forEach(function(e){
				sum += e*e;
			});

			if (sum == 1){
				return true;
			}else{
				return happy(sum, s);
			}
		}

		return happy(n, s);
	};

 	it("19 is happy number", function(){
 		isHappy(19).should.eql(true);
 	});

 	it("2 is not happy number", function(){
 		isHappy(2).should.eql(false);
 	});

 	it("10 is happy number", function(){
 		isHappy(10).should.eql(true);
 	});
});


describe("Reverse Linked List", function(){
	function ListNode(val) {
		this.val = val;
		this.next = null;
	};

	var reverseList = function(head) {
		var newhead = new ListNode(0);

		while(head != null){
			var h = head.next;
			head.next = newhead.next;
			newhead.next = head;
			head = h;
		}

		return newhead.next;
	};

	it("1,2 => 2,1", function(){
		var n1 = new ListNode(1);
 		var n2 = new ListNode(2);
 		n1.next = n2;

 		var r = reverseList(n1);
 		r.val.should.eql(2);
 		r.next.val.should.eql(1);
 	});
});


