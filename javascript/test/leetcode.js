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

describe("Count Primes", function(){
    var countPrimes = function(n) {

        var arr = [];
        for(var i=0; i<n; ++i){
            arr.push(true);
        }
        arr[0] = arr[1] = false;

        var max = Math.floor(Math.sqrt(n-1));
        for (i=2; i<=max; ++i){
            if (arr[i] === false){
                continue;
            }

            for(var j=i*i; j<n; j+=i ){
                arr[j] = false;
            }
        }

        return arr.reduce(function(a, b){
            return b? a+1:a;
        }, 0);
    };

    it("Count Primes", function(){
        countPrimes(3).should.eql(1);
        countPrimes(6).should.eql(3);
        countPrimes(12).should.eql(5);
    });
});

describe("Remove Linked List Elements", function(){
    function ListNode(val) {
        this.val = val;
        this.next = null;
    }

    /**
     * @param {ListNode} head
     * @param {number} val
     * @return {ListNode}
     */
    var removeElements = function(head, val) {
        var newhead = new ListNode(0);
        var newtail = newhead;

        while(head != null){
            if (head.val == val){
                head = head.next;
            }else{
                newtail.next = head;
                newtail = newtail.next;
                head = head.next;
                newtail.next= null;
            }
        }

        return newhead.next;
    };

    it("1,2,3 => 1,3", function(){
        var n1 = new ListNode(1);
        var n2 = new ListNode(2);
        var n3 = new ListNode(3);
        n1.next = n2;
        n2.next = n3;

        var r = removeElements(n1, 2);
        r.val.should.eql(1);
        r.next.val.should.eql(3);
    });
});

describe("Number of Islands ", function(){
    /**
     * @param {character[][]} grid
     * @return {number}
     */
    var numIslands = function(grid) {
        if (grid.length == 0){
            return 0;
        }

        var arr = new Array(grid.length);
        var flag=0;
        var dirs=[[0,1],[0,-1],[1,0],[-1,0]];
        var width = grid[0].length;
        var height = grid.length;

        function init(){
            for(var i=0; i<height;++i){
                arr[i] = new Array(width);
                for(var j=0;j<width; ++j){
                     arr[i][j]=0;
                }
            }
        }

        function unresolved(i, j){
            return grid[i][j] == '1' && arr[i][j]==0;
        }

        function fill(row,col, f){
            arr[row][col] = f;
            dirs.forEach(function(dir){
                var r = row + dir[0];
                var c = col + dir[1];
                if (r < 0 || r>=height){
                }else if(c<0 || c>=width){
                }else{
                    if (unresolved(r, c)){
                        fill(r, c, f);
                    }
                }
            });
        }

        init();
        for(i=0; i<height; ++i){
            for(j=0; j<width; ++j){
                if(unresolved(i,j)){
                    ++flag;
                    fill(i, j, flag);
                }
            }
        }

        return flag;
    };

    it("empty grid", function(){
        grid = [];
        numIslands(grid).should.eql(0);
    });

    it("1x2 grid", function(){
        grid = ["10"];
        numIslands(grid).should.eql(1);
    });

    it("3x3 grid", function(){
        grid = ['111',
                '010',
                '111'];
        numIslands(grid).should.eql(1);
    });

    it("5x5 grid", function(){
        grid = ['11000',
                '11000',
                '00100',
                '00100',
                '00011'];
        numIslands(grid).should.eql(3);
    });
});

describe("Rotate Array", function(){
    /**
     * @param {number[]} nums
     * @param {number} k
     * @return {void} Do not return anything, modify nums in-place instead.
     */
    var rotate = function(nums, k) {
        var len = nums.length;
        if (k>len){
            k = k%len;
        }

        function getOldIndex(x){
            if (x<k){
                return len-k+x;
            }else{
                return x-k;
            }
        }

        var newArr = nums.map(function(cv, index){
            var j = getOldIndex(index);
            return nums[j];
        });

        newArr.forEach(function(cv, index){
            nums[index] = cv;
        });
    };

    it("case 1", function(){
        nums = [1,2,3,4,5,6];
        rotate(nums, 2);
        nums.should.eql([5,6,1,2,3,4]);
    });

    it("case 2", function(){
        nums = [1,2];
        rotate(nums, 1);
        nums.should.eql([2,1]);
    });

    it("one elem", function(){
        nums = [1];
        rotate(nums, 2);
        nums.should.eql([1]);
    });
});

describe("Compare Version Numbers", function(){
    /**
     * @param {string} version1
     * @param {string} version2
     * @return {number}
     */
    var compareVersion = function(version1, version2) {
        var v1=version1.split('.').map(function(e){
            return Number(e);
        });

        var v2=version2.split('.').map(function(e){
            return Number(e);
        });

        if(v1.length<v2.length){
            for(var i=0, len=v2.length-v1.length; i<len; ++i){
                v1.push('0');
            }
        }else if(v1.length>v2.length){
            for(var i=0, len=v1.length-v2.length; i<len; ++i){
                v2.push('0');
            }
        }

        for(var i=0,len=v1.length; i<len; ++i){
            if(v1[i] > v2[i]){
                return 1;
            }else if(v1[i] < v2[i]){
                return -1;
            }
        }

        return 0;
    };

    it("1.1 < 1.2", function(){
        compareVersion("1.1", "1.2").should.eql(-1);
    });

    it("1 < 1.2", function(){
        compareVersion("1", "1.2").should.eql(-1);
    });

    it("1.2 > 1.1", function(){
        compareVersion("1.2", "1.1").should.eql(1);
    });

    it("1.2.3 = 1.2.3", function(){
        compareVersion("1.2.3", "1.2.3").should.eql(0);
    });
});

describe("Insertion Sort List ", function(){
     function ListNode(val) {
         this.val = val;
         this.next = null;
     }

    /**
     * @param {ListNode} head
     * @return {ListNode}
     */
    var insertionSortList = function(head) { 
        var newhead = new ListNode(0);

        var p = head;
        while(p != null){
            var q = p.next;

            var r = newhead;
            while(r.next && r.next.val <= p.val){
                r = r.next;
            }
            p.next = r.next;
            r.next = p;

            p = q;
        }

        return newhead.next;
    };

    it("2->1", function(){
        var n = new ListNode(2);
        n.next = new ListNode(1);

        var list = insertionSortList(n);
        list.val.should.eql(1);
        list.next.val.should.eql(2);
    });

    it("2", function(){
        var n = new ListNode(2);

        var list = insertionSortList(n);
        list.val.should.eql(2);
    });
});

describe("3Sum Closest", function(){
    /**
     * @param {number[]} nums
     * @param {number} target
     * @return {number}
     */
    var threeSumClosest = function(nums, target) {
        return 0;
    };

    it("-1,2,1,-4", function(){
        var nums = [-1, 2, 1, -4];
        var target = 1;
        threeSumClosest(nums, target).should.eql(2);
    })
});
