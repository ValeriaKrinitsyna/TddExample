using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Task2CSHARP;

namespace SystemOfLinearEquationsCSHARP
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void CorrectIndexing()
        {
            int n = 3;
            SystemOfLinearEquations s = new SystemOfLinearEquations(n);
            s.addEquation(new LinearEquation("4,-5,2,1"));
            s.addEquation(new LinearEquation("3,-3,2,2"));
            s.addEquation(new LinearEquation("2,-3,1,3"));
            Assert.AreEqual(new LinearEquation("3,-3,2,2"), s[1]);
        }

        [TestMethod]
        public void CorrectSolving()
        {
            int n = 3;
            SystemOfLinearEquations s = new SystemOfLinearEquations(n);
            s.addEquation(new LinearEquation("4,-5,2,1"));
            s.addEquation(new LinearEquation("3,-3,2,2"));
            s.addEquation(new LinearEquation("2,-3,1,3"));
            s.steppingUp();
            double[] solve1 = new double[] { -11, -5, 10 };
            double[] solve2 = s.solveSystem();
            bool check = true;
            for (int i = 0; i < n; i++)
            {
                if (Math.Abs(solve1[i] - solve2[i]) > 1e-9)
                    check = false;
            }
            Assert.AreEqual(true, check);
        }
        
        [TestMethod]
        [ExpectedException(typeof(ArgumentException))]
        public void CheckNoSolutions()
        {
            int n = 3;
            SystemOfLinearEquations s = new SystemOfLinearEquations(n);
            s.addEquation(new LinearEquation("4,-3,2,-1,8"));
            s.addEquation(new LinearEquation("3,-2,1,-3,7"));
            s.addEquation(new LinearEquation("5,-3,1,-8,1"));
            s.steppingUp();
            Assert.Equals(typeof(ArgumentException), s.solveSystem());
        }

        [TestMethod]
        [ExpectedException(typeof(ArgumentException))]
        public void InfinitelyManySolutions()
        {
            int n = 3;
            SystemOfLinearEquations s = new SystemOfLinearEquations(n);
            s.addEquation(new LinearEquation("2,3,-1,1,1"));
            s.addEquation(new LinearEquation("8,12,-9,8,3"));
            s.addEquation(new LinearEquation("4,6,3,-2,3"));
            s.addEquation(new LinearEquation("2,3,9,-7,3"));
            s.steppingUp();
            Assert.Equals(typeof(ArgumentException), s.solveSystem());
        }
    }
}
