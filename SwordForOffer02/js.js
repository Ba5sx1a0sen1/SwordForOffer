function  Find(target, array)
{
    // write code here
    var found = false;
    if(array!==null&&array.length>0&&array[0].length>0){
        var rows = array.length;
        var columns = array[0].length;
        var row = 0;//从第一行开始扫描
        var column = columns-1; //定义最后一列的索引
        while(row<rows&&column>=0){
            if(array[row][column]==target){
                found = true;
                return found;
            }else if(array[row][column]>target){
                column--;
            }else{
                row++;
            }
        }
    }
    return found;
}
