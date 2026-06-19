import java.util.*;
import java.io.*;
import java.nio.charset.StandardCharsets;

public class Main {
	static class Node {
		int id;
		Set<Integer> connNodes;
		Set<Integer> dsts;

		public Node(int id) {
			this.id = id;
			this.connNodes = new HashSet<>();
			this.dsts = new HashSet<>();
		}

		void show() {
			for (Integer dst : dsts) {
				System.out.println((id + 1) + " " + (dst + 1));
			}
		}
	}

	Node[] allNodes;
	Map<Integer, Node> oddNodes;
	Map<Integer, Node> processingNodes;

	Main(Node[] nodes) {
		this.allNodes = nodes;
		this.oddNodes = new HashMap<>();
		this.processingNodes = new HashMap<>();
		for (int i = 0; i < nodes.length; ++i) {
			this.processingNodes.put(i, nodes[i]);
			if (nodes[i].connNodes.size() % 2 == 0) {
				this.oddNodes.put(i, nodes[i]);
			}
		}
		calc();
		showResult();
	}

	void showResult() {
		if (!this.processingNodes.isEmpty()) {
			System.out.println("-1");
		} else {
			for (Node node : allNodes) {
				node.show();
			}
		}
	}

	void calc() {
		while (!oddNodes.isEmpty()) {
			Node node = oddNodes.values().stream().findFirst().get();
			if (node.connNodes.isEmpty()) {
				this.oddNodes.remove(node.id);
				this.processingNodes.remove(node.id);
				continue;
			}
			// edgeを2本取り出す
			Iterator<Integer> it = node.connNodes.iterator();
			int next0 = it.next();
			int next1 = it.next();
			// 取り出したedgeを削除する
			node.connNodes.remove(next0);
			node.connNodes.remove(next1);
			node.dsts.add(next0);
			node.dsts.add(next1);
			int id = node.id;
			this.allNodes[next0].connNodes.remove(id);
			this.allNodes[next1].connNodes.remove(id);
			// 処理したことで枝が全部なくなれば処理対象から外す
			if (this.allNodes[id].connNodes.isEmpty()) {
				this.processingNodes.remove(id);
				this.oddNodes.remove(id);
			}
			if (this.allNodes[next0].connNodes.isEmpty()) {
				this.processingNodes.remove(next0);
				this.oddNodes.remove(id);
			}
			if (this.allNodes[next1].connNodes.isEmpty()) {
				this.processingNodes.remove(next1);
				this.oddNodes.remove(id);
			}
			// next郡のodd関係を見直す．srcのほうは2本単位で抜くのでodd関係に変更はない
			if (this.allNodes[next0].connNodes.size() % 2 == 0 && !this.allNodes[next0].connNodes.isEmpty()) {
				this.oddNodes.put(next0, this.allNodes[next0]);
			} else {
				this.oddNodes.remove(next0);
			}
			if (this.allNodes[next1].connNodes.size() % 2 == 0 && !this.allNodes[next1].connNodes.isEmpty()) {
				this.oddNodes.put(next1, this.allNodes[next1]);
			} else {
				this.oddNodes.remove(next1);
			}
		}
	}

	public static void main(String[] args) throws IOException {
		InputStreamReader reader = new InputStreamReader(System.in, StandardCharsets.UTF_8);
		BufferedReader in = new BufferedReader(reader);
		String[] tokens = in.readLine().split(" ");
		int N = Integer.parseInt(tokens[0]);
		int M = Integer.parseInt(tokens[1]);

		Node[] nodes = new Node[N];
		for (int i = 0; i < N; ++i) {
			nodes[i] = new Node(i);
		}
		for (int i = 0; i < M; ++i) {
			tokens = in.readLine().split(" ");
			int id0 = Integer.parseInt(tokens[0]) - 1;
			int id1 = Integer.parseInt(tokens[1]) - 1;
			nodes[id0].connNodes.add(id1);
			nodes[id1].connNodes.add(id0);
		}

		Main ins = new Main(nodes);
		in.close();
	}

}