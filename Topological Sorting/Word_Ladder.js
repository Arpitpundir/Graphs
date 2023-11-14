var ladderLength = function(beginWord, endWord, wordList) {
    const queue = [];
    queue.push(beginWord);
    const visitedWord = new Set(), availableWord = new Set(wordList);

    let ans = 0;
    while(queue.length){
        const size = queue.length;
        ans++;

        for(let k=0;k<size;k++){
            
            const curr = queue[0];
            queue.shift();
            if(curr === endWord) return ans;

            for(let j=0;j<curr.length; j++){

                for(let i=0;i<27;i++){

                    const nextChar = String.fromCharCode('a'.charCodeAt(0)+i);
                    if(nextChar[0] == curr[j]) continue;
                    const temp = curr.substring(0, j) + String.fromCharCode('a'.charCodeAt(0)+i) + curr.substring(j+1);
                    if(availableWord.has(temp) && !visitedWord.has(temp)){
                        visitedWord.add(temp);
                        queue.push(temp);
                    }
                }
            }
        }
    }
    return 0;
};