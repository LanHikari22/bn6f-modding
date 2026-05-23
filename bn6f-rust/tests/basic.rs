//! These here are integration tests. Unit tests test internally and have access to private information within a module.
//! Integration tests only have access to the outer interface and use the module like other systems that use it.

use todo::*;

#[test]
fn test_add() {
    println!("How did this fail?");

    assert_eq!(add(1, 1), 2);
}
