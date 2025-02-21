use std::fmt::Debug;

struct Node<T>
{
    data: T,
    next: Option<Box<Node<T>>> // Might contain Some value or None
}

struct LinkedList<T>
{
    head: Option<Box<Node<T>>>
}

impl<T: Debug> LinkedList<T>
{
    pub fn new() -> Self
    {
        return LinkedList{ head: None };
    }

    pub fn push_front(&mut self, data: T)
    {
        let new_node: Box<Node<T>> = Box::new(Node {
            data,
            next: self.head.take() // takes out the value and leaves the head with None
        });

        self.head = Some(new_node); // As LinkedList struct expects and Option
    }

    pub fn pop(&mut self) -> Option<T>
    {
        let value: Option<Box<Node<T>>> = self.head.take();
        match value 
        {
            Some(mut node) => {
                self.head = node.next.take();
                return Some(node.data);
            },
            None => None
        }
    }

    pub fn len(&self) -> u32
    {
        let mut len: u32 = 0;
        let mut current: &Option<Box<Node<T>>> = &self.head;

        while let Some(node) = current{
            len += 1;
            current = &node.next;
        }

        return len;
    }

    pub fn print_list(&self)
    {   
        let mut current: &Option<Box<Node<T>>> = &self.head;

        while let Some(node) = current 
        {
            print!("{:?}, ", node.data);
            current = &node.next;
        }
    }
}

fn main()
{
    let mut l = LinkedList::new();

    l.push_front("a");
    l.push_front("b");
    l.push_front("c");

    println!("Length: {}", l.len());
    l.pop();
    println!("Length: {}",l.len());

    l.print_list();
}