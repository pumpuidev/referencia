import unittest
import osztok

class MyTest(unittest.TestCase):

    def setUp(self):
        self.xs = [1, 2, 4, 13, 26, 52]

    def test_oszto1(self):
        self.assertEqual(osztok.osztoi(52), self.xs)

    def test_oszto2(self):
        self.assertTrue(4 in osztok.osztoi(20))

    def test_oszto3(self):
        self.assertRaises(TypeError, osztok.osztoi, "a")
            
if __name__ == '__main__':
    unittest.main()

# python unittest1.py 
# 
# python unittest1.py  -v



