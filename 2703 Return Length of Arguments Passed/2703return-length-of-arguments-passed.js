/**
 * @param {...(null|boolean|number|string|Array|Object)} args
 * @return {number}
 */
var argumentsLength = (...args) => args.length; /*{
  /*  let l=0;
    for(const key in args){
        l++;
    }
    return l;
    return args.length;
};*/

/**
 * argumentsLength(1, 2, 3); // 3
 */