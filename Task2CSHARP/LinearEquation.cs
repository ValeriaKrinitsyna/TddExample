using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace Task2CSHARP
{
    public class LinearEquation
    {
        private List<double> coefs;

        public LinearEquation(string _coef) // equation from the string of coefficients
        {
            string[] coef = Regex.Split(_coef, @"[^\d.-]");
            coefs = new List<double>();
            for (int i = 0; i < coef.Length; i++)
            {
                if (coef[i] != "")
                {
                    coef[i] = coef[i].Replace('.', ',');
                    coefs.Add(double.Parse(coef[i]));
                }
            }
        }

        public LinearEquation(double[] coef) // equation from the array
        {
            coefs = new List<double>(coef);
        }

        public LinearEquation(List<double> coef) // equation from the list
        {
            coefs = new List<double>(coef);
        }

        

        public LinearEquation(IEnumerable<double> coef) 
        {
            coefs = new List<double>(coef);
        }

        public LinearEquation(int n) // equation from n zeros
        {
            if (n > 0)
            {
                coefs = new List<double>();
                for (int i = 0; i <= n; i++)
                    coefs.Add(0);
            }
            else throw new ArgumentException();
        }

        public int Size
        {
            get { return coefs.Count; }
        }

        public void randInit()
        {
            Random rand = new Random();
            for (int i = 0; i < Size; i++)
                coefs[i] = rand.Next(55) / 10;
        }

        public void equalInit(double value)
        {
            for (int i = 0; i < Size; i++)
                coefs[i] = value;
        }

        public double this[int index]
        {
            get
            {
                if (index >= 0 && index < Size)
                    return coefs[index];
                else throw new IndexOutOfRangeException();
            }
            set
            {
                if (index >= 0 && index < Size)
                    coefs[index] = value;
                else throw new IndexOutOfRangeException();
            }
        }

        public static LinearEquation operator +(LinearEquation a, LinearEquation b) // a+b
        {
            var result = a.coefs.Zip(b.coefs, (first, second) => first + second);
            return new LinearEquation(result);
        }

        public static LinearEquation operator -(LinearEquation a, LinearEquation b) // a-b
        {
            var result = a.coefs.Zip(b.coefs, (first, second) => first - second);
            return new LinearEquation(result);
        }

        public static LinearEquation operator *(LinearEquation a, double r) // a*r
        {
            List<double> result = new List<double>();
            for (int i = 0; i < a.Size; i++)
                result.Add(a[i] * r);
            return new LinearEquation(result);
        }

        public static LinearEquation operator *(double r, LinearEquation a) // r*a
        {
            return a * r;
        }

        public static LinearEquation operator -(LinearEquation a) // -a
        {
            List<double> result = new List<double>();
            for (int i = 0; i < a.Size; i++)
                result.Add(-a[i]);
            return new LinearEquation(result);
        }

        public override string ToString()
        {
            string res = "";
            int i;
            for (i = 0; i < Size - 2; i++)
                res += (coefs[i + 1] >= 0) ? (coefs[i].ToString() + 'x' + (i + 1).ToString() + '+') : (coefs[i].ToString() + 'x' + (i + 1).ToString());
            res += (coefs[i].ToString() + 'x' + (i + 1).ToString());
            res += '=' + coefs[Size - 1].ToString();
            return res;
        }

        public static bool operator ==(LinearEquation a, LinearEquation b)
        {
            return a.Equals(b);
        }

        public static bool operator !=(LinearEquation a, LinearEquation b)
        {
            return !(a == b);
        }

        public static implicit operator double[] (LinearEquation a)
        {
            return a.coefs.ToArray();
        }

        public static bool operator false(LinearEquation a)
        {
            if (a)
                return false;
            else
                return true;
        }

        public static bool operator true(LinearEquation a)
        {
            for (int i = 0; i < a.Size - 1; i++)
                if (a[i] != 0)
                    return true;
            return (a[a.Size - 1] != 0) ? false : true;
        }

        public override bool Equals(object obj)
        {
            LinearEquation a = (LinearEquation)obj;
            for (int i = 0; i < Size; i++)
                if (Math.Abs(this[i] - a[i]) > 1e-9)
                    return false;
            return true;
        }

        public bool IsNull()
        {
            for (int i = 0; i < Size; i++)
                if (this[i] != 0)
                    return false;
            return true;
        }

        public void CopyTo(LinearEquation a)
        {
            a.coefs = coefs.ToList();
        }
    }
}
