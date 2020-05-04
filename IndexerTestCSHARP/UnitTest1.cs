using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Task1CSHARP;

namespace IndexerTestCSHARP
{
    [TestClass]
    public class UnitTest1
    {
        double[] array = new double[] { 1, 2, 3, 4 };

        [TestMethod]
        public void HaveCorrectLength()
        {
            var indexer = new IndexerCSHARP(array, 1, 2); // {2,3}
            Assert.AreEqual(2, indexer.Length);
        }
        [TestMethod]
        public void GetCorrectly()
        {
            var indexer = new IndexerCSHARP(array, 1, 2); // {2,3}
            Assert.AreEqual(2, indexer[0]);
            Assert.AreEqual(3, indexer[1]);
        }
        [TestMethod]
        public void SetCorrectly()
        {
            var indexer = new IndexerCSHARP(array, 1, 2);// {2,3}
            indexer[0] = 10; // {10,3}
            Assert.AreEqual(10, array[1]);
        }
        [TestMethod]
        public void IndexerDoesNotCopyArray()
        {
            var indexer1 = new IndexerCSHARP(array, 1, 2); // {2,3}
            var indexer2 = new IndexerCSHARP(array, 0, 2); // {1,2}
            indexer1[0] = 100500; // {100500,2}
            Assert.AreEqual(100500, indexer2[1]);
        }
        [TestMethod]
        [ExpectedException(typeof(ArgumentException))]
        public void FailWithWrongArguments1()
        {
            Assert.Equals(typeof(ArgumentException), new IndexerCSHARP(array, -1, 3)); //start can't be -1
        }
        [TestMethod]
        [ExpectedException(typeof(ArgumentException))]
        public void FailWithWrongArguments2()
        {
            Assert.Equals(typeof(ArgumentException), new IndexerCSHARP(array, 1, -1)); // length can't be -1
        }
        [TestMethod]
        [ExpectedException(typeof(ArgumentException))]
        public void FailWithWrongArguments3()
        {
            Assert.Equals(typeof(ArgumentException), new IndexerCSHARP(array, 1, 10)); // length can't be bigger than arrayLength
        }
        [TestMethod]
        [ExpectedException(typeof(IndexOutOfRangeException))]
        public void FailWithWrongIndexing1()
        {
            var indexer = new IndexerCSHARP(array, 1, 2);
            Assert.Equals(typeof(IndexOutOfRangeException), indexer[-1]); // index can't be less than 0
        }
        [TestMethod]
        [ExpectedException(typeof(IndexOutOfRangeException))]
        public void FailWithWrongIndexing2()
        {

            var indexer = new IndexerCSHARP(array, 1, 2);
            Assert.AreNotEqual(typeof(IndexOutOfRangeException), indexer[10]); // index can't be bigger than 3
        }
    }
}
