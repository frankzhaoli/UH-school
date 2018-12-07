import java.io.File
import java.util.Stack
import java.util.Scanner

fun main(args: Array<String>)
{
    print("Enter file name: ")
    val input=Scanner(System.`in`)
    val filename=input.next()

    //val filename="test.txt"
    val lines : List<String> = File(filename).readLines()
    val list : MutableList<String> =  ArrayList()
    var stack : Stack<Int> = Stack()
    var results : MutableList<Int> = ArrayList()
    var savePrint : MutableList<String> = ArrayList()
    var i : Int = 0

    lines.forEach{line-> list.add(line)}
    lines.forEach{line-> savePrint.add(line)}

    processList(list, stack, results)

    results=results.distinct().toMutableList()

    //println(results)
    savePrint=savePrint.distinct().toMutableList()
    //println(savePrint)
    savePrint.removeAt(1)

    for(item in savePrint)
    {
        var str : String
        str=item.plus(" = ")
        str=str.plus(results.get(i))
        println(str)
        i++
    }

    println("DONE")
}

fun processList(args: MutableList<String>, stack: Stack<Int>, results: MutableList<Int>): MutableList<String>
{
    if(args.isEmpty())
    {
        return args
    }
    else if(args.isNotEmpty())
    {
        var temp=args.component1()
        temp=temp.replace("(", " ")
        temp=temp.replace(")", " ")
        temp=temp.replace(",", " ")
        temp=temp.replace("add", "+")
        temp=temp.replace("multiply", "*")
        temp=temp.replace("  ", " ")
        //println(temp)
        args.removeAt(0)

        var item=temp.split(" ")
        var newList=item.toMutableList()
        newList.removeAt(newList.lastIndex)

        calculate(newList, stack)

        //println(stack.peek())
        val a=stack.peek()
        results.add(a)

        return processList(args, stack, results)
    }
    //results.distinct()
    //println(results)

    return args
}

fun calculate(args: MutableList<String>, stack: Stack<Int>): MutableList<String> {

    if (args.isEmpty())
    {
        return args
    }
    else
    {
        val top = args.removeAt(args.lastIndex)
        //println(top)
        //is operator
        if (top == "+" || top == "*") {
            //println(top)
            val num1 = stack.pop()
            val num2 = stack.pop()
            var result = 0

            if (top == "+") {
                result = num1.plus(num2)
            } else if (top == "*") {
                result = num1.times(num2)
            }

            stack.push(result)
        }
        //is num
        else if (top != "")
        {
            //println(top)
            stack.push(top.toInt())
        }

        return calculate(args, stack)
    }

    return args
}
