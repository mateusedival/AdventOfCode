use std::{fs, collections::HashMap};

enum NodeType {
    Start,
    End,
    Big,
    Small
}

struct Node {
    name: String,
    typeOf: NodeType,
    nb: Vec<Box<Node>>,
}

impl Node {
    fn new(name: String, typeOf: NodeType) -> Self {
        Node { name, typeOf, nb: Vec::new() }
    }

    fn push(&mut self, value: Node) {
        self.nb.push(Box::new(value));
    }
}

fn dfs(node: &Node, visited: &mut HashMap<String,bool>) -> i64 {
    match node.typeOf {
        NodeType::End => return 1,
        NodeType::Start => return 0,
        _ => {
            visited.insert(node.name.to_owned(), true);
        } 
    }

    let paths = node.nb.iter().fold(0, |acc , nb|{
        let v = visited.get(&nb.name).unwrap_or(&false).to_owned();
        if (matches!(nb.typeOf, NodeType::Small) && !v) ||
            matches!(nb.typeOf, NodeType::Big) {
            acc + dfs(&*nb,visited)
        } else {
            acc + 0
        }
    });

    return paths;
}


pub fn run() -> Result<i64,()> {
    let input = fs::read_to_string("src\\input\\day_11.txt").unwrap();
    
    let mut nodes: HashMap<String,Vec<Node>> = HashMap::new();

    input
        .lines()
        .for_each(|line|{
            let pair: Vec<&str> = line.split("-").collect();
            let mut types  = [NodeType::Start, NodeType::End];
            for i in 0..pair.len() {
                types[i] = if pair[i] == "start" {
                    NodeType::Start
                } else if pair[i].chars().all(char::is_uppercase) {
                    NodeType::Big
                } else if pair[i] == "end" {
                    NodeType::End
                } else {
                    NodeType::Small
                };
            }
            let p1 = pair[0].to_string();
            let p2 = pair[1].to_string();
            let node1 = if nodes.contains_key(&p1) {
                nodes.get_mut(&p1).unwrap()
            } else { vec![Node::new(p1, types[0])] };
           
        });


    Ok(1)
}


pub fn run_2() -> Result<i64,()> {
    let input = fs::read_to_string("src\\input\\day_11.txt").unwrap();


    Ok(2)

}
