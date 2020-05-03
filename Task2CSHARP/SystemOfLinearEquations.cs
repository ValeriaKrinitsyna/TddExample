using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task2CSHARP
{
    public class SystemOfLinearEquations
    {
        private List<LinearEquation> system = new List<LinearEquation>();
        private int n;

        public SystemOfLinearEquations(int n)
        {
            this.n = n;
        }

        public LinearEquation this[int index]
        {
            get
            {
                if (index >= 0 && index < Size)
                    return system[index];
                else throw new IndexOutOfRangeException();
            }
            set
            {
                if (index >= 0 && index < Size)
                    system[index] = value;
                else throw new IndexOutOfRangeException();
            }
        }

        public int Size => system.Count;

        public void addEquation(LinearEquation a)
        {
            if (a.Size == n + 1)
                system.Add(a);
            else throw new ArgumentException();
        }

        public void removeEquation(int index)
        {
            system.RemoveAt(index);
        }

        public void steppingUp()
        {
            int c, z;
            double p1, p2;
            for (int i = 0; i < Size; i++)
            {
                z = i;
                if (this[i][z] == 0)
                {
                    while (this[i][z] == 0 && z < n) z++;
                    c = 1;
                    while ((i + c) < Size && this[i + c][z] == 0) c++;
                    if ((i + c) == Size)
                        return;
                    swap(this[i], this[i + c]);
                }
                for (int j = i + 1; j < Size; j++)
                {
                    p1 = this[i][z];
                    p2 = this[j][z];
                    this[j] = this[j] * p1 - this[i] * p2;
                }
            }
        }

        public double[] solveSystem()
        {
            while (this[Size - 1].IsNull())
                this.removeEquation(Size - 1);
            if (this[Size - 1])
            {
                if (Size == n)
                {
                    double[] solve = new double[n];
                    for (int i = Size - 1; i >= 0; i--)
                    {
                        solve[i] = this[i][n];
                        for (int j = i + 1; j < n; j++)
                        {
                            solve[i] -= this[i][j] * solve[j];
                        }
                        solve[i] /= this[i][i];
                    }
                    return solve;
                }
                else throw new ArgumentException("The system has infinitely many solutions!");
            }
            else throw new ArgumentException("The system has no solutions!");
        }

        private void swap(LinearEquation a, LinearEquation b)
        {
            LinearEquation tmp = new LinearEquation(a);
            b.CopyTo(a);
            tmp.CopyTo(b);
        }

        public override string ToString()
        {
            string res = "";
            for (int i = 0; i < Size; i++)
                res += this[i].ToString() + '\n';
            return res;
        }
    }
}
