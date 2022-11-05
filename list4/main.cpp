#include <bits/stdc++.h>

using namespace std;

struct Bucket 
{
    int local_depth = 0;
    vector<int> values;
};

class Directory 
{

    int global_depth;
    int bucket_size;

    map<int, Bucket*> buckets;

    public:
        Directory(int depth, int bucket_size) {
            this->global_depth = depth;
            this->bucket_size = bucket_size;

            buckets[0] = new Bucket;     
        }

        ~Directory() {

        }

        // Pega os bits mais significativos (profundida do hash binário - global_depth)
        int hash(int value) {
            return value & ((1<<global_depth) - 1);
        }

        void split(int bucket_index, Bucket* bckt) {
            Bucket* new_bucket = new Bucket;
            
            vector<int> temp;
            for(auto i: bckt->values) {
                temp.push_back(i);
            }

            bckt->values.clear();

            if(bckt->local_depth == global_depth) { // Inserção caso 3: bucket está completo e só possui uma referência.

                // Atribui o novo bucket à nova posição correta, o novo índice (índice do atual + 2^global_depth).
                buckets[bucket_index ^ (1<<global_depth)] = new_bucket;

                if(global_depth != 0) {
                    for(int i = 0; i < (1<<global_depth); i++) {
                        if(i != bucket_index)
                            // Cria os novos índices da expansão,
                            // atribuindo os endereços dos buckets antigos a esses índices.
                            buckets[i ^ (1<<global_depth)] = buckets[i];
                    }
                }

                global_depth += 1;

                bckt->local_depth += 1;
                new_bucket->local_depth = bckt->local_depth;

                for(auto i: temp) {
                    int bucket_index = hash(i);
                    buckets[bucket_index]->values.push_back(i);
                }
            } else {// Inserção caso 2: bucket está completo e só possui uma referência.
                int k = bucket_index & (1<<bckt->local_depth - 1);
                vector<int> indices;

                for (int i = 0; i < (1<<global_depth); i++)
                {
                    int last = i & (1<<(bckt->local_depth)) - 1;
                    if(last == k)
                        indices.push_back(i);
                }
                
                bckt->local_depth += 1;
                new_bucket->local_depth = bckt->local_depth;
                
                // Atribui o novo bucket as novas posições corretas, os novos índices (a metade do vetor indices).
                for (int i = indices.size()/2; i < indices.size(); i++) {
                    buckets[indices[i]] = new_bucket;
                }

                for(auto i: temp) {
                    int bucket_index = hash(i);
                    buckets[bucket_index]->values.push_back(i);
                }
            }
            
        }

        void merge() {
            for(int i = 0; i<(1<<(global_depth-1));i++) {
                int h = i & ( ( 1<< ((buckets[i]->local_depth)-1) ) - 1);
                
                Bucket *curr = buckets[i];
                Bucket *matched = buckets[ i ^ (1<<(buckets[i]->local_depth-1)) ];
                
                if(curr != matched) {
                    int size = curr->values.size() + matched->values.size();
                    
                    if(size <= bucket_size) {

                        // TODO: fazer funcionar
                        // copy(all(matched->values), back_inserter(curr->values));
                        
                        vector<int> temp;
                        
                        for(auto i : buckets) {
                            if(i.second == matched)
                                temp.push_back(i.first);
                        }
                        
                        delete matched;

                        for(auto j : temp)
                            buckets[j] = buckets[i];

                        buckets[i]->local_depth --;
                    }
                }
            }
        }

        void shrink() {
            set<Bucket *> buckets_temp;

            for(auto i : buckets)
                buckets_temp.insert(i.second);

            int count = 0;
            int size = buckets_temp.size();
            
            for(auto i : buckets_temp)
                if((global_depth - (i->local_depth)) == 1)
                    count++;
            
            if(count == size)
                global_depth--;
        }

        void insert(int value) {
            int bucket_index = hash(value);

            if(buckets[bucket_index]->values.size() == bucket_size) {
                cout << "bucket full " << endl;
                cout << "spliting bucket..." << endl;
                split(bucket_index, buckets[bucket_index]);

                insert(value);
            } else { // Inserção caso 1: bucket ainda tem espaço.
                cout << "inserting value: " << value << endl;
                buckets[bucket_index]->values.push_back(value);
            }
        }

        void remove(int value) {

            if(search(value)) {
                int bucket_index = hash(value);

                vector<int>::iterator it;
                Bucket* bckt = buckets[bucket_index];

                for(it = bckt->values.begin(); it != bckt->values.end(); it++) {
                    if(*it == value) {
                        bckt->values.erase(it);
                        cout << "Value deleted successfully" << endl;
                        break;
                    }
                }

                merge();

                shrink();
            } else {
                cout << "No value to be deleted" << endl;
            }
        }

        int search(int value) {
            int bucket_index = hash(value);

            for(auto i: buckets[bucket_index]->values) {
                if(i == value)
                    return 1;
            }

            return 0; 
        }

        void printHash() {
            for(int i = 0; i < buckets.size(); i++) {
                cout << "Bucket [" << i << "]:";
                
                for(auto k: buckets[i]->values) {
                    cout << " " << k;
                }

                cout << endl;
            }
        }

};


int main(int argc, char const *argv[])
{
    int initial_depth = 0;
    int bucket_size = 4;

    Directory dir(initial_depth, bucket_size);

    dir.insert(1);
    dir.insert(12);
    dir.insert(13);
    dir.insert(14);
    dir.insert(15);

    cout << "Is value 16 present? " << dir.search(16) << endl;
    cout << "Is value 15 present? " << dir.search(15) << endl;

    dir.printHash();

    dir.remove(16);
    dir.remove(13);

    dir.printHash();

    return 0;
}
