let array = [64, 25, 12, 22, 11]

// Selection Sort
const selectionSort = (arr) => {
    let n = arr.length;

    for(let i=0; i<n; i++){
        let minIndex = i;
        for(let j=i+1; j<n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        [arr[i], arr[minIndex]] = [arr[minIndex], arr[i]];
    }
   console.log(arr);
}
// selectionSort(array)

// array.sort((a, b) => b - a)
// console.log(array)

// Given a sorted array, find if there exist two numbers that sum up to a given target. Use the
// two-pointer technique.

let sortedArray =  [64, 25, 22, 12, 11];
let target = 32;
function twoSum(sortedArray){
    let i=0, j= sortedArray.length-1;
    let found = false;
    while(i<j){
        let sum = sortedArray[i] + sortedArray[j];
        if(sum == target){
            console.log([sortedArray[i], sortedArray[j]]);
            console.log(i,j);
            found = true;
            break;
        } else if(sum > target) i++;
        else j--;
    }
    !found && console.log("No pair found");
}
twoSum(sortedArray);