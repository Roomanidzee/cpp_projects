#include <omp.h>
#include <mpi.h>

using namespace std;

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    srand(time(NULL) * rank);

    //Установить количество потоков
    omp_set_num_threads(3);
    //Код внутри этой директивы будет распараллелен на потоки
#pragma omp parallel
    { //отсюда
        cout << "proc: " << rank << " number: " << rand() << endl;
    } //и до сюда

    MPI_Finalize();
    return 0;
}