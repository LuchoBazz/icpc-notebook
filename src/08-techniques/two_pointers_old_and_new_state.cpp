// sequence:             [ a1,   a2,   a3, ...]
//                         |      |    |
//                         v      v    v
// new state:      [new0,  new1, new2, new3, ...]
//                    |     |      |
//                    v     v      v
// new state: [old0, old1, old2,  old3, ...]

// new state:       [old0,  old1,  old2, old3, ...]
//                    |      |      |
//                    v      v      v
// new state: [new0, new1, new2,  new3, ...]

// int last = default_val1;
// int now = default_val2;
// for(int i = 0; i < n; ++i){
//     last =  now;
//     now = process_logic(element, old)
// }