// sequence: [a1, a2, a3, ..., an]
// slow runner: [slow] ->->
// fast runner: [fast] ->->->->

// int slow = 0;
// for(int fast = 0; fast < n; ++fast){
//     if(slow_condition(slow)) {
//         slow = slow.next;
//         slow += 1;
//     }
//     process_logic(slow, fast);
// }