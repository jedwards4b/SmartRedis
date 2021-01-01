import time
import numpy as np
from silc import Dataset, Client

CLUSTER = True

def test_put_get_dataset(mock_data):
    """test sending and recieving a dataset with 2D tensors
    of every datatype
    """

    data = mock_data.create_data((10,10))

    # Create a dataset to put
    dataset = Dataset("test-dataset")
    for index, tensor in enumerate(data):
        key = f"tensor_{str(index)}"
        dataset.add_tensor(key, tensor)

    client = Client(CLUSTER, False)
    client.put_dataset(dataset)

    rdataset = client.get_dataset("test-dataset")
    for index, tensor in enumerate(data):
        key = f"tensor_{str(index)}"
        rtensor = rdataset.get_tensor(key)
        np.testing.assert_array_equal(
            rtensor, tensor, "Dataset returned from get_dataset not the same as sent dataset"
        )