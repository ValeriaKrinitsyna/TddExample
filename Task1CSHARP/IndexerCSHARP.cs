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
        public IndexerCSHARP(double[] array, int start, int length)
        {
            if (start < 0 || length <= 0 || array.Length <= start + length)
                throw new ArgumentException();
            this.array = array;
            this.start = start;
            this.end = start + length - 1;
        }
        public int Length
        {
            get { return end - start + 1; }
        }

        public double this[int index]
        {
            get
            {
                if (index < 0 || index >= this.Length)
                    throw new IndexOutOfRangeException();
                return this.array[index + start];
            }
            set
            {
                if (index < 0 || index >= this.Length)
                    throw new IndexOutOfRangeException();
                this.array[index + start] = value;
            }
        }
    }
}
