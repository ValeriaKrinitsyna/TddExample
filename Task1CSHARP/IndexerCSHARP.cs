using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task1CSHARP
{
    public class IndexerCSHARP
    {
        double[] array;
        int start, end;
        public IndexerCSHARP(double[] array, int start, int length) // access to the part of array by the some element and length from this element
        {
            if (start < 0 || length <= 0 || array.Length <= start + length) //input check
                throw new ArgumentException();
            this.array = array;
            this.start = start;
            this.end = start + length - 1;
        }
        public int Length //gets length
        {
            get { return end - start + 1; }
        }

        public double this[int index] //access to the element by it's index
        {
            get
            {
                if (index < 0 || index >= this.Length) //index check
                    throw new IndexOutOfRangeException();
                return this.array[index + start]; //pointer to element
            }
            set
            {
                if (index < 0 || index >= this.Length) //index check
                    throw new IndexOutOfRangeException();
                this.array[index + start] = value; //set value to an element
            }
        }
    }
}
